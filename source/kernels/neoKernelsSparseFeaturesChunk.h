// ----------------------------------------------------------------------------
//  OgmaNeo
//  Copyright(c) 2016 Ogma Intelligent Systems Corp. All rights reserved.
//
//  This copy of OgmaNeo is licensed to you under the terms described
//  in the OGMANEO_LICENSE.md file included in this distribution.
// ----------------------------------------------------------------------------

#pragma once

#if !defined(_NEOKERNELSSPARSEFEATURESCHUNK_OCL_HEADER)
#define _NEOKERNELSSPARSEFEATURESCHUNK_OCL_HEADER

#include <string>

const std::string neoKernelsSparseFeaturesChunk_ocl[] = {
"// ----------------------------------------------------------------------------\n",
"//  OgmaNeo\n",
"//  Copyright(c) 2016 Ogma Intelligent Systems Corp. All rights reserved.\n",
"//\n",
"//  This copy of OgmaNeo is licensed to you under the terms described\n",
"//  in the OGMANEO_LICENSE.md file included in this distribution.\n",
"// ----------------------------------------------------------------------------\n",
"\n",
"// ----------------------------------------- Samplers -----------------------------------------\n",
"\n",
"constant sampler_t defaultSampler = CLK_NORMALIZED_COORDS_FALSE |\n",
"    CLK_ADDRESS_CLAMP_TO_EDGE |\n",
"    CLK_FILTER_NEAREST;\n",
"\n",
"constant sampler_t normalizedClampedNearestSampler = CLK_NORMALIZED_COORDS_TRUE |\n",
"    CLK_ADDRESS_CLAMP |\n",
"    CLK_FILTER_NEAREST;\n",
"\n",
"constant sampler_t normalizedClampedToEdgeNearestSampler = CLK_NORMALIZED_COORDS_TRUE |\n",
"    CLK_ADDRESS_CLAMP_TO_EDGE |\n",
"    CLK_FILTER_NEAREST;\n",
"\n",
"constant sampler_t unnormalizedClampedNearestSampler = CLK_NORMALIZED_COORDS_FALSE |\n",
"    CLK_ADDRESS_CLAMP |\n",
"    CLK_FILTER_NEAREST;\n",
"\n",
"constant sampler_t defaultNormalizedSampler = CLK_NORMALIZED_COORDS_TRUE |\n",
"    CLK_ADDRESS_CLAMP_TO_EDGE |\n",
"    CLK_FILTER_NEAREST;\n",
"\n",
"constant sampler_t defaultUnnormalizedSampler = CLK_NORMALIZED_COORDS_FALSE |\n",
"    CLK_ADDRESS_CLAMP_TO_EDGE |\n",
"    CLK_FILTER_NEAREST;\n",
"\n",
"// ----------------------------------------- Common -----------------------------------------\n",
"\n",
"float randFloat(uint2* state) {\n",
"    const float invMaxInt = 1.0f / 4294967296.0f;\n",
"    uint x = (*state).x * 17 + (*state).y * 13123;\n",
"    (*state).x = (x << 13) ^ x;\n",
"    (*state).y ^= (x << 7);\n",
"\n",
"    uint tmp = x * (x * x * 15731 + 74323) + 871483;\n",
"\n",
"    return convert_float(tmp) * invMaxInt;\n",
"}\n",
"\n",
"float randNormal(uint2* state) {\n",
"    float u1 = randFloat(state);\n",
"    float u2 = randFloat(state);\n",
"\n",
"    return sqrt(-2.0f * log(u1)) * cos(6.28318f * u2);\n",
"}\n",
"\n",
"float sigmoid(float x) {\n",
"    return 1.0f / (1.0f + exp(-x));\n",
"}\n",
"\n",
"float relu(float x, float leak) {\n",
"    x += 0.5f;\n",
"\n",
"    if (x > 1.0f)\n",
"        return 1.0f + (x - 1.0f) * leak;\n",
"\n",
"    return x > 0.0f ? x : x * leak;\n",
"}\n",
"\n",
"float relud(float x, float leak) {\n",
"    x += 0.5f;\n",
"\n",
"    return x > 0.0f && x < 1.0f ? 1.0f : leak;\n",
"}\n",
"\n",
"bool inBounds0(int2 position, int2 upperBound) {\n",
"    return position.x >= 0 && position.x < upperBound.x && position.y >= 0 && position.y < upperBound.y;\n",
"}\n",
"\n",
"bool inBounds(int2 position, int2 lowerBound, int2 upperBound) {\n",
"    return position.x >= lowerBound.x && position.x < upperBound.x && position.y >= lowerBound.y && position.y < upperBound.y;\n",
"}\n",
"\n",
"int2 project(int2 position, float2 toScalars) {\n",
"    return (int2)(position.x * toScalars.x + 0.5f, position.y * toScalars.y + 0.5f);\n",
"}\n",
"\n",
"// Initialize a random uniform 2D image (X field)\n",
"void kernel randomUniform2D(write_only image2d_t values, uint2 seed, float2 minMax) {\n",
"    uint2 seedValue = seed + (uint2)(get_global_id(0) * 29 + 12, get_global_id(1) * 16 + 23) * 36;\n",
"\n",
"    int2 position = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"    float value = randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x;\n",
"\n",
"    write_imagef(values, position, (float4)(value, 0.0f, 0.0f, 0.0f));\n",
"}\n",
"\n",
"// Initialize a random uniform 3D image (X field)\n",
"void kernel randomUniform3D(write_only image3d_t values, uint2 seed, float2 minMax) {\n",
"    uint2 seedValue = seed + (uint2)(get_global_id(0) * 12 + 76 + get_global_id(2) * 3, get_global_id(1) * 21 + 42 + get_global_id(2) * 7) * 12;\n",
"\n",
"    int3 position = (int3)(get_global_id(0), get_global_id(1), get_global_id(2));\n",
"\n",
"    float value = randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x;\n",
"\n",
"    write_imagef(values, (int4)(position, 0), (float4)(value, 0.0f, 0.0f, 0.0f));\n",
"}\n",
"\n",
"// Initialize a random uniform 2D image (XY fields)\n",
"void kernel randomUniform2DXY(write_only image2d_t values, uint2 seed, float2 minMax) {\n",
"    uint2 seedValue = seed + (uint2)(get_global_id(0) * 15 + 66, get_global_id(1) * 61 + 2) * 56;\n",
"\n",
"    int2 position = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"    float2 v = (float2)(randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x, randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x);\n",
"\n",
"    write_imagef(values, position, (float4)(v.x, v.y, 0.0f, 0.0f));\n",
"}\n",
"\n",
"// Initialize a random uniform 2D image (XYZ fields)\n",
"void kernel randomUniform2DXYZ(write_only image2d_t values, uint2 seed, float2 minMax) {\n",
"    uint2 seedValue = seed + (uint2)(get_global_id(0) * 15 + 66, get_global_id(1) * 61 + 2) * 56;\n",
"\n",
"    int2 position = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"    float3 v = (float3)(randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x, randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x, randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x);\n",
"\n",
"    write_imagef(values, position, (float4)(v.x, v.y, v.z, 0.0f));\n",
"}\n",
"\n",
"// Initialize a random uniform 2D image (XZ fields)\n",
"void kernel randomUniform2DXZ(write_only image2d_t values, uint2 seed, float2 minMax) {\n",
"    uint2 seedValue = seed + (uint2)(get_global_id(0) * 29 + 12, get_global_id(1) * 16 + 23) * 36;\n",
"\n",
"    int2 position = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"    float2 v = (float2)(randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x, randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x);\n",
"\n",
"    write_imagef(values, position, (float4)(v.x, 0.0f, v.y, 0.0f));\n",
"}\n",
"\n",
"// Initialize a random uniform 3D image (XY fields)\n",
"void kernel randomUniform3DXY(write_only image3d_t values, uint2 seed, float2 minMax) {\n",
"    uint2 seedValue = seed + (uint2)(get_global_id(0) * 12 + 76 + get_global_id(2) * 3, get_global_id(1) * 21 + 42 + get_global_id(2) * 7) * 12;\n",
"\n",
"    int3 position = (int3)(get_global_id(0), get_global_id(1), get_global_id(2));\n",
"\n",
"    float2 v = (float2)(randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x, randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x);\n",
"\n",
"    write_imagef(values, (int4)(position, 0), (float4)(v.x, v.y, 0.0f, 0.0f));\n",
"}\n",
"\n",
"// Initialize a random uniform 3D image (XZ fields)\n",
"void kernel randomUniform3DXZ(write_only image3d_t values, uint2 seed, float2 minMax) {\n",
"    uint2 seedValue = seed + (uint2)(get_global_id(0) * 12 + 76 + get_global_id(2) * 3, get_global_id(1) * 21 + 42 + get_global_id(2) * 7) * 12;\n",
"\n",
"    int3 position = (int3)(get_global_id(0), get_global_id(1), get_global_id(2));\n",
"\n",
"    float2 v = (float2)(randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x, randFloat(&seedValue) * (minMax.y - minMax.x) + minMax.x);\n",
"\n",
"    write_imagef(values, (int4)(position, 0), (float4)(v.x, 0.0f, v.y, 0.0f));\n",
"}\n",
"// --------------------------------------------------------------------------\n",
"//	Ogma Toolkit(OTK)\n",
"//	Copyright(c) 2016 Ogma Intelligent Systems Corp. All rights reserved.\n",
"// --------------------------------------------------------------------------\n",
"\n",
"// ----------------------------------------- Sparse Features -----------------------------------------\n",
"\n",
"void kernel sfcAddSample(read_only image2d_t visibleStates,\n",
"    read_only image3d_t samplesBack, write_only image3d_t samplesFront,\n",
"    int numSamples)\n",
"{\n",
"    int2 position = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"    float visibleState = read_imagef(visibleStates, defaultSampler, position).x;\n",
"\n",
"    for (int s = 1; s < numSamples; s++) {\n",
"        float samplePrev = read_imagef(samplesBack, defaultSampler, (int4)(position.x, position.y, s - 1, 0)).x;\n",
"\n",
"        write_imagef(samplesFront, (int4)(position.x, position.y, s, 0), (float4)(samplePrev, 0.0f, 0.0f, 0.0f));\n",
"    }\n",
"\n",
"    write_imagef(samplesFront, (int4)(position.x, position.y, 0, 0), (float4)(visibleState, 0.0f, 0.0f, 0.0f));\n",
"}\n",
"\n",
"void kernel sfcStimulus(read_only image3d_t samples,\n",
"	read_only image2d_t hiddenSummationTempBack, write_only image2d_t hiddenSummationTempFront, read_only image3d_t weights,\n",
"	int2 visibleSize, float2 hiddenToVisible, int2 chunkSize, float2 chunksToHidden, int radius, int numSamples, uchar ignoreMiddle)\n",
"{\n",
"	int2 hiddenPosition = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"	int2 chunkPosition = (int2)(hiddenPosition.x / chunkSize.x, hiddenPosition.y / chunkSize.y);\n",
"	float2 chunkCenterf = ((float2)(chunkPosition.x, chunkPosition.y) + (float2)(0.5f)) * chunksToHidden;\n",
"	int2 chunkCenter = (int2)(chunkCenterf.x, chunkCenterf.y);\n",
"\n",
"	int2 visiblePositionCenter = project(chunkCenter, hiddenToVisible);\n",
"\n",
"	float sum = read_imagef(hiddenSummationTempBack, defaultSampler, hiddenPosition).x;\n",
"\n",
"    float subSum = 0.0f;\n",
"\n",
"	float count = 0.0f;\n",
"\n",
"	int2 fieldLowerBound = visiblePositionCenter - (int2)(radius);\n",
"\n",
"	for (int s = 0; s < numSamples; s++) {\n",
"		for (int dx = -radius; dx <= radius; dx++)\n",
"			for (int dy = -radius; dy <= radius; dy++) {\n",
"				int2 visiblePosition = visiblePositionCenter + (int2)(dx, dy);\n",
"\n",
"				if (ignoreMiddle && dx == 0 && dy == 0)\n",
"					continue;\n",
"\n",
"				if (inBounds0(visiblePosition, visibleSize)) {\n",
"					int2 offset = visiblePosition - fieldLowerBound;\n",
"\n",
"					int wi = s + numSamples * (offset.y + offset.x * (radius * 2 + 1));\n",
"\n",
"					float weight = read_imagef(weights, defaultSampler, (int4)(hiddenPosition.x, hiddenPosition.y, wi, 0)).x;\n",
"\n",
"					float sample = read_imagef(samples, defaultSampler, (int4)(visiblePosition.x, visiblePosition.y, s, 0)).x;\n",
"\n",
"					float delta = sample - weight;\n",
"\n",
"					subSum += -delta * delta;\n",
"					count += 1.0f;\n",
"				}\n",
"			}\n",
"	}\n",
"\n",
"    write_imagef(hiddenSummationTempFront, hiddenPosition, (float4)(sum + subSum / fmax(0.0001f, count), 0.0f, 0.0f, 0.0f));\n",
"}\n",
"\n",
"void kernel sfcActivate(read_only image2d_t hiddenStimuli, read_only image2d_t hiddenStatesPrev,\n",
"	write_only image2d_t hiddenActivationsFront)\n",
"{\n",
"	int2 hiddenPosition = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"	float hiddenStimulus = read_imagef(hiddenStimuli, defaultSampler, hiddenPosition).x;\n",
"\n",
"	write_imagef(hiddenActivationsFront, hiddenPosition, (float4)(exp(hiddenStimulus), 0.0f, 0.0f, 0.0f));\n",
"}\n",
"\n",
"void kernel sfcInhibit(read_only image2d_t activations,\n",
"	write_only image2d_t hiddenStatesFront,\n",
"	write_only image2d_t chunkWinners,\n",
"	int2 hiddenSize, int2 chunkSize)\n",
"{\n",
"	int2 chunkPosition = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"	int2 hiddenStartPosition = chunkPosition * chunkSize;\n",
"\n",
"	float maxValue = -99999.0f;\n",
"	int2 maxDelta = (int2)(0);\n",
"\n",
"	for (int dx = 0; dx < chunkSize.x; dx++)\n",
"		for (int dy = 0; dy < chunkSize.y; dy++) {\n",
"			int2 hiddenPosition = hiddenStartPosition + (int2)(dx, dy);\n",
"\n",
"			if (inBounds0(hiddenPosition, hiddenSize)) {\n",
"                float activation = read_imagef(activations, defaultSampler, hiddenPosition).x;\n",
"\n",
"				if (activation > maxValue) {\n",
"					maxValue = activation;\n",
"\n",
"					maxDelta = (int2)(dx, dy);\n",
"				}\n",
"			}\n",
"		}\n",
"\n",
"	write_imagei(chunkWinners, chunkPosition, (int4)(maxDelta.x, maxDelta.y, 0, 0));\n",
"\n",
"    for (int dx = 0; dx < chunkSize.x; dx++)\n",
"		for (int dy = 0; dy < chunkSize.y; dy++) {\n",
"			int2 hiddenPosition = hiddenStartPosition + (int2)(dx, dy);\n",
"\n",
"			if (inBounds0(hiddenPosition, hiddenSize)) {\n",
"				//float tracePrev = read_imagef(hiddenStatesBack, defaultSampler, hiddenPosition).y;\n",
"\n",
"                if (dx == maxDelta.x && dy == maxDelta.y)\n",
"					write_imagef(hiddenStatesFront, hiddenPosition, (float4)(1.0f, 0.0f, 0.0f, 0.0f));\n",
"				else\n",
"					write_imagef(hiddenStatesFront, hiddenPosition, (float4)(0.0f, 0.0f, 0.0f, 0.0f));\n",
"			}\n",
"		}\n",
"}\n",
"\n",
"void kernel sfcInhibitOther(read_only image2d_t activations,\n",
"	write_only image2d_t hiddenStatesFront,\n",
"	int2 hiddenSize, int2 chunkSize)\n",
"{\n",
"	int2 chunkPosition = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"	int2 hiddenStartPosition = chunkPosition * chunkSize;\n",
"\n",
"	float maxValue = -99999.0f;\n",
"	int2 maxDelta = (int2)(0);\n",
"\n",
"	for (int dx = 0; dx < chunkSize.x; dx++)\n",
"		for (int dy = 0; dy < chunkSize.y; dy++) {\n",
"			int2 hiddenPosition = hiddenStartPosition + (int2)(dx, dy);\n",
"\n",
"			if (inBounds0(hiddenPosition, hiddenSize)) {\n",
"                float activation = read_imagef(activations, defaultSampler, hiddenPosition).x;\n",
"\n",
"				if (activation > maxValue) {\n",
"					maxValue = activation;\n",
"\n",
"					maxDelta = (int2)(dx, dy);\n",
"				}\n",
"			}\n",
"		}\n",
"\n",
"    for (int dx = 0; dx < chunkSize.x; dx++)\n",
"		for (int dy = 0; dy < chunkSize.y; dy++) {\n",
"			int2 hiddenPosition = hiddenStartPosition + (int2)(dx, dy);\n",
"\n",
"			if (inBounds0(hiddenPosition, hiddenSize)) {\n",
"				//float tracePrev = read_imagef(hiddenStatesBack, defaultSampler, hiddenPosition).y;\n",
"\n",
"                if (dx == maxDelta.x && dy == maxDelta.y)\n",
"					write_imagef(hiddenStatesFront, hiddenPosition, (float4)(1.0f, 0.0f, 0.0f, 0.0f));\n",
"				else\n",
"					write_imagef(hiddenStatesFront, hiddenPosition, (float4)(0.0f, 0.0f, 0.0f, 0.0f));\n",
"			}\n",
"		}\n",
"}\n",
"\n",
"void kernel sfcReconstruct(read_only image2d_t hiddenStates, read_only image2d_t hiddenActivations,\n",
"    write_only image3d_t recons, read_only image3d_t weights,\n",
"    int2 visibleSize, int2 hiddenSize, float2 visibleToHidden, float2 hiddenToVisible, int2 chunkSize, float2 chunksToHidden, int radius, int2 reverseRadii, int numSamples)\n",
"{\n",
"    int2 visiblePosition = (int2)(get_global_id(0), get_global_id(1));\n",
"    int2 hiddenPositionCenter = project(visiblePosition, visibleToHidden);\n",
"\n",
"	// Find chunks for this input\n",
"    for (int s = 0; s < numSamples; s++) {\n",
"        float recon = 0.0f;\n",
"\n",
"        for (int dx = -reverseRadii.x; dx <= reverseRadii.x; dx++)\n",
"            for (int dy = -reverseRadii.y; dy <= reverseRadii.y; dy++) {\n",
"                int2 hiddenPosition = hiddenPositionCenter + (int2)(dx, dy);\n",
"\n",
"                if (inBounds0(hiddenPosition, hiddenSize)) {\n",
"					int2 chunkPosition = (int2)(hiddenPosition.x / chunkSize.x, hiddenPosition.y / chunkSize.y);\n",
"					float2 chunkCenterf = ((float2)(chunkPosition.x, chunkPosition.y) + (float2)(0.5f)) * chunksToHidden;\n",
"					int2 chunkCenter = (int2)(chunkCenterf.x, chunkCenterf.y);\n",
"\n",
"                    // Next layer node's receptive field\n",
"                    int2 fieldCenter = project(chunkCenter, hiddenToVisible);\n",
"\n",
"                    int2 fieldLowerBound = fieldCenter - (int2)(radius);\n",
"                    int2 fieldUpperBound = fieldCenter + (int2)(radius + 1); // So is included in inBounds\n",
"\n",
"                    // Check for containment\n",
"                    if (inBounds(visiblePosition, fieldLowerBound, fieldUpperBound)) {\n",
"                        int2 offset = visiblePosition - fieldLowerBound;\n",
"\n",
"                        float hiddenState = read_imagef(hiddenStates, defaultSampler, hiddenPosition).x;\n",
"						float hiddenActivation = read_imagef(hiddenActivations, defaultSampler, hiddenPosition).x;\n",
"\n",
"                        int wi = s + numSamples * (offset.y + offset.x * (radius * 2 + 1));\n",
"\n",
"                        float weight = read_imagef(weights, defaultSampler, (int4)(hiddenPosition.x, hiddenPosition.y, wi, 0)).x;\n",
"\n",
"                        recon += hiddenState * hiddenActivation * weight;\n",
"                    }\n",
"                }\n",
"            }\n",
"\n",
"        write_imagef(recons, (int4)(visiblePosition.x, visiblePosition.y, s, 0), (float4)(recon, 0.0f, 0.0f, 0.0f));\n",
"    }\n",
"}\n",
"\n",
"void kernel sfcLearnWeights(read_only image2d_t hiddenStates,\n",
"	read_only image2d_t chunkWinners,\n",
"    read_only image3d_t samples,\n",
"	read_only image3d_t weightsBack, write_only image3d_t weightsFront,\n",
"	int2 hiddenSize, int2 visibleSize, float2 hiddenToVisible, int2 chunkSize, float2 chunksToHidden, int radius, float weightAlpha, int numSamples, float gamma)\n",
"{\n",
"	int2 hiddenPosition = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"	int2 chunkPosition = (int2)(hiddenPosition.x / chunkSize.x, hiddenPosition.y / chunkSize.y);\n",
"	float2 chunkCenterf = ((float2)(chunkPosition.x, chunkPosition.y) + (float2)(0.5f)) * chunksToHidden;\n",
"	int2 chunkCenter = (int2)(chunkCenterf.x, chunkCenterf.y);\n",
"\n",
"	int2 visiblePositionCenter = project(chunkCenter, hiddenToVisible);\n",
"\n",
"	int2 fieldLowerBound = visiblePositionCenter - (int2)(radius);\n",
"\n",
"	int2 chunkWinner = read_imagei(chunkWinners, defaultSampler, chunkPosition).xy;\n",
"\n",
"	int2 hiddenStartPosition = chunkPosition * chunkSize;\n",
"\n",
"	int2 delta = (hiddenStartPosition + chunkWinner) - hiddenPosition;\n",
"\n",
"	float strength = exp(-(delta.x * delta.x + delta.y * delta.y) * gamma);\n",
"\n",
"	//float hiddenState = read_imagef(hiddenStates, defaultSampler, hiddenPosition).x;\n",
"\n",
"	for (int s = 0; s < numSamples; s++) {\n",
"		for (int dx = -radius; dx <= radius; dx++)\n",
"			for (int dy = -radius; dy <= radius; dy++) {\n",
"				int2 visiblePosition = visiblePositionCenter + (int2)(dx, dy);\n",
"\n",
"				if (inBounds0(visiblePosition, visibleSize)) {\n",
"					int2 offset = visiblePosition - fieldLowerBound;\n",
"\n",
"					int wi = s + numSamples * (offset.y + offset.x * (radius * 2 + 1));\n",
"\n",
"					float weightPrev = read_imagef(weightsBack, defaultSampler, (int4)(hiddenPosition.x, hiddenPosition.y, wi, 0)).x;\n",
"\n",
"					float sample = read_imagef(samples, defaultSampler, (int4)(visiblePosition.x, visiblePosition.y, s, 0)).x;\n",
"					//float recon = read_imagef(recons, defaultSampler, (int4)(visiblePosition.x, visiblePosition.y, s, 0)).x;\n",
"\n",
"					float sLearn = strength * (sample - weightPrev);\n",
"\n",
"					write_imagef(weightsFront, (int4)(hiddenPosition.x, hiddenPosition.y, wi, 0), (float4)(weightPrev + weightAlpha * sLearn, 0.0f, 0.0f, 0.0f));\n",
"				}\n",
"			}\n",
"	}\n",
"}\n",
"\n",
"void kernel sfcLearnBiases(read_only image2d_t hiddenStimuli, read_only image2d_t hiddenStates,\n",
"	read_only image2d_t biasesBack, write_only image2d_t biasesFront, float activeRatio, float biasAlpha)\n",
"{\n",
"	int2 hiddenPosition = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"	float hiddenState = read_imagef(hiddenStates, defaultSampler, hiddenPosition).x;\n",
"	float hiddenStimulus = read_imagef(hiddenStimuli, defaultSampler, hiddenPosition).x;\n",
"\n",
"	// Bias update\n",
"	float biasPrev = read_imagef(biasesBack, defaultSampler, hiddenPosition).x;\n",
"\n",
"	write_imagef(biasesFront, hiddenPosition, (float4)(biasPrev + biasAlpha * (activeRatio - hiddenState)));\n",
"}\n",
"\n",
"void kernel sfcDeriveInputs(read_only image2d_t inputs, read_only image2d_t outputsBack, write_only image2d_t outputsFront, float lambda) {\n",
"	int2 position = (int2)(get_global_id(0), get_global_id(1));\n",
"\n",
"	float input = read_imagef(inputs, defaultSampler, position).x;\n",
"\n",
"	float tracePrev = read_imagef(outputsBack, defaultSampler, position).y;\n",
"\n",
"	write_imagef(outputsFront, position, (float4)(input, lambda * tracePrev + (1.0f - lambda) * input, 0.0f, 0.0f));\n",
"}\n",
};

#endif