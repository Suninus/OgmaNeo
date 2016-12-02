// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_SPARSEFEATURESCHUNK_OGMANEO_SCHEMAS_H_
#define FLATBUFFERS_GENERATED_SPARSEFEATURESCHUNK_OGMANEO_SCHEMAS_H_

#include "flatbuffers/flatbuffers.h"

#include "Helpers_generated.h"

namespace ogmaneo {
namespace schemas {

struct VisibleChunkLayerDesc;

struct VisibleChunkLayer;

struct SparseFeaturesChunkDesc;

struct SparseFeaturesChunk;

MANUALLY_ALIGNED_STRUCT(4) VisibleChunkLayerDesc FLATBUFFERS_FINAL_CLASS {
 private:
  ogmaneo::schemas::int2 _size_;
  int32_t _radius_;
  uint8_t _ignoreMiddle_;
  int8_t __padding0;
  int16_t __padding1;
  float _weightAlpha_;
  float _lambda_;

 public:
  VisibleChunkLayerDesc() { memset(this, 0, sizeof(VisibleChunkLayerDesc)); }
  VisibleChunkLayerDesc(const VisibleChunkLayerDesc &_o) { memcpy(this, &_o, sizeof(VisibleChunkLayerDesc)); }
  VisibleChunkLayerDesc(const ogmaneo::schemas::int2 &__size, int32_t __radius, uint8_t __ignoreMiddle, float __weightAlpha, float __lambda)
    : _size_(__size), _radius_(flatbuffers::EndianScalar(__radius)), _ignoreMiddle_(flatbuffers::EndianScalar(__ignoreMiddle)), __padding0(0), __padding1(0), _weightAlpha_(flatbuffers::EndianScalar(__weightAlpha)), _lambda_(flatbuffers::EndianScalar(__lambda)) { (void)__padding0; (void)__padding1; }

  const ogmaneo::schemas::int2 &_size() const { return _size_; }
  ogmaneo::schemas::int2 &mutable__size() { return _size_; }
  int32_t _radius() const { return flatbuffers::EndianScalar(_radius_); }
  void mutate__radius(int32_t __radius) { flatbuffers::WriteScalar(&_radius_, __radius); }
  uint8_t _ignoreMiddle() const { return flatbuffers::EndianScalar(_ignoreMiddle_); }
  void mutate__ignoreMiddle(uint8_t __ignoreMiddle) { flatbuffers::WriteScalar(&_ignoreMiddle_, __ignoreMiddle); }
  float _weightAlpha() const { return flatbuffers::EndianScalar(_weightAlpha_); }
  void mutate__weightAlpha(float __weightAlpha) { flatbuffers::WriteScalar(&_weightAlpha_, __weightAlpha); }
  float _lambda() const { return flatbuffers::EndianScalar(_lambda_); }
  void mutate__lambda(float __lambda) { flatbuffers::WriteScalar(&_lambda_, __lambda); }
};
STRUCT_END(VisibleChunkLayerDesc, 24);

struct VisibleChunkLayer FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__DERIVEDINPUT = 4,
    VT__WEIGHTS = 6,
    VT__HIDDENTOVISIBLE = 8,
    VT__VISIBLETOHIDDEN = 10,
    VT__REVERSERADII = 12
  };
  const ogmaneo::schemas::DoubleBuffer2D *_derivedInput() const { return GetPointer<const ogmaneo::schemas::DoubleBuffer2D *>(VT__DERIVEDINPUT); }
  ogmaneo::schemas::DoubleBuffer2D *mutable__derivedInput() { return GetPointer<ogmaneo::schemas::DoubleBuffer2D *>(VT__DERIVEDINPUT); }
  const ogmaneo::schemas::DoubleBuffer3D *_weights() const { return GetPointer<const ogmaneo::schemas::DoubleBuffer3D *>(VT__WEIGHTS); }
  ogmaneo::schemas::DoubleBuffer3D *mutable__weights() { return GetPointer<ogmaneo::schemas::DoubleBuffer3D *>(VT__WEIGHTS); }
  const ogmaneo::schemas::float2 *_hiddenToVisible() const { return GetStruct<const ogmaneo::schemas::float2 *>(VT__HIDDENTOVISIBLE); }
  ogmaneo::schemas::float2 *mutable__hiddenToVisible() { return GetStruct<ogmaneo::schemas::float2 *>(VT__HIDDENTOVISIBLE); }
  const ogmaneo::schemas::float2 *_visibleToHidden() const { return GetStruct<const ogmaneo::schemas::float2 *>(VT__VISIBLETOHIDDEN); }
  ogmaneo::schemas::float2 *mutable__visibleToHidden() { return GetStruct<ogmaneo::schemas::float2 *>(VT__VISIBLETOHIDDEN); }
  const ogmaneo::schemas::int2 *_reverseRadii() const { return GetStruct<const ogmaneo::schemas::int2 *>(VT__REVERSERADII); }
  ogmaneo::schemas::int2 *mutable__reverseRadii() { return GetStruct<ogmaneo::schemas::int2 *>(VT__REVERSERADII); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__DERIVEDINPUT) &&
           verifier.VerifyTable(_derivedInput()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__WEIGHTS) &&
           verifier.VerifyTable(_weights()) &&
           VerifyField<ogmaneo::schemas::float2>(verifier, VT__HIDDENTOVISIBLE) &&
           VerifyField<ogmaneo::schemas::float2>(verifier, VT__VISIBLETOHIDDEN) &&
           VerifyField<ogmaneo::schemas::int2>(verifier, VT__REVERSERADII) &&
           verifier.EndTable();
  }
};

struct VisibleChunkLayerBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__derivedInput(flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _derivedInput) { fbb_.AddOffset(VisibleChunkLayer::VT__DERIVEDINPUT, _derivedInput); }
  void add__weights(flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer3D> _weights) { fbb_.AddOffset(VisibleChunkLayer::VT__WEIGHTS, _weights); }
  void add__hiddenToVisible(const ogmaneo::schemas::float2 *_hiddenToVisible) { fbb_.AddStruct(VisibleChunkLayer::VT__HIDDENTOVISIBLE, _hiddenToVisible); }
  void add__visibleToHidden(const ogmaneo::schemas::float2 *_visibleToHidden) { fbb_.AddStruct(VisibleChunkLayer::VT__VISIBLETOHIDDEN, _visibleToHidden); }
  void add__reverseRadii(const ogmaneo::schemas::int2 *_reverseRadii) { fbb_.AddStruct(VisibleChunkLayer::VT__REVERSERADII, _reverseRadii); }
  VisibleChunkLayerBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  VisibleChunkLayerBuilder &operator=(const VisibleChunkLayerBuilder &);
  flatbuffers::Offset<VisibleChunkLayer> Finish() {
    auto o = flatbuffers::Offset<VisibleChunkLayer>(fbb_.EndTable(start_, 5));
    return o;
  }
};

inline flatbuffers::Offset<VisibleChunkLayer> CreateVisibleChunkLayer(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _derivedInput = 0,
    flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer3D> _weights = 0,
    const ogmaneo::schemas::float2 *_hiddenToVisible = 0,
    const ogmaneo::schemas::float2 *_visibleToHidden = 0,
    const ogmaneo::schemas::int2 *_reverseRadii = 0) {
  VisibleChunkLayerBuilder builder_(_fbb);
  builder_.add__reverseRadii(_reverseRadii);
  builder_.add__visibleToHidden(_visibleToHidden);
  builder_.add__hiddenToVisible(_hiddenToVisible);
  builder_.add__weights(_weights);
  builder_.add__derivedInput(_derivedInput);
  return builder_.Finish();
}

struct SparseFeaturesChunkDesc FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__HIDDENSIZE = 4,
    VT__CHUNKSIZE = 6,
    VT__BIASALPHA = 8,
    VT__GAMMA = 10,
    VT__INITWEIGHTRANGE = 12,
    VT__VISIBLELAYERDESCS = 14
  };
  const ogmaneo::schemas::int2 *_hiddenSize() const { return GetStruct<const ogmaneo::schemas::int2 *>(VT__HIDDENSIZE); }
  ogmaneo::schemas::int2 *mutable__hiddenSize() { return GetStruct<ogmaneo::schemas::int2 *>(VT__HIDDENSIZE); }
  const ogmaneo::schemas::int2 *_chunkSize() const { return GetStruct<const ogmaneo::schemas::int2 *>(VT__CHUNKSIZE); }
  ogmaneo::schemas::int2 *mutable__chunkSize() { return GetStruct<ogmaneo::schemas::int2 *>(VT__CHUNKSIZE); }
  float _biasAlpha() const { return GetField<float>(VT__BIASALPHA, 0.0f); }
  bool mutate__biasAlpha(float __biasAlpha) { return SetField(VT__BIASALPHA, __biasAlpha); }
  float _gamma() const { return GetField<float>(VT__GAMMA, 0.0f); }
  bool mutate__gamma(float __gamma) { return SetField(VT__GAMMA, __gamma); }
  const ogmaneo::schemas::float2 *_initWeightRange() const { return GetStruct<const ogmaneo::schemas::float2 *>(VT__INITWEIGHTRANGE); }
  ogmaneo::schemas::float2 *mutable__initWeightRange() { return GetStruct<ogmaneo::schemas::float2 *>(VT__INITWEIGHTRANGE); }
  const flatbuffers::Vector<const VisibleChunkLayerDesc *> *_visibleLayerDescs() const { return GetPointer<const flatbuffers::Vector<const VisibleChunkLayerDesc *> *>(VT__VISIBLELAYERDESCS); }
  flatbuffers::Vector<const VisibleChunkLayerDesc *> *mutable__visibleLayerDescs() { return GetPointer<flatbuffers::Vector<const VisibleChunkLayerDesc *> *>(VT__VISIBLELAYERDESCS); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<ogmaneo::schemas::int2>(verifier, VT__HIDDENSIZE) &&
           VerifyField<ogmaneo::schemas::int2>(verifier, VT__CHUNKSIZE) &&
           VerifyField<float>(verifier, VT__BIASALPHA) &&
           VerifyField<float>(verifier, VT__GAMMA) &&
           VerifyField<ogmaneo::schemas::float2>(verifier, VT__INITWEIGHTRANGE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__VISIBLELAYERDESCS) &&
           verifier.Verify(_visibleLayerDescs()) &&
           verifier.EndTable();
  }
};

struct SparseFeaturesChunkDescBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__hiddenSize(const ogmaneo::schemas::int2 *_hiddenSize) { fbb_.AddStruct(SparseFeaturesChunkDesc::VT__HIDDENSIZE, _hiddenSize); }
  void add__chunkSize(const ogmaneo::schemas::int2 *_chunkSize) { fbb_.AddStruct(SparseFeaturesChunkDesc::VT__CHUNKSIZE, _chunkSize); }
  void add__biasAlpha(float _biasAlpha) { fbb_.AddElement<float>(SparseFeaturesChunkDesc::VT__BIASALPHA, _biasAlpha, 0.0f); }
  void add__gamma(float _gamma) { fbb_.AddElement<float>(SparseFeaturesChunkDesc::VT__GAMMA, _gamma, 0.0f); }
  void add__initWeightRange(const ogmaneo::schemas::float2 *_initWeightRange) { fbb_.AddStruct(SparseFeaturesChunkDesc::VT__INITWEIGHTRANGE, _initWeightRange); }
  void add__visibleLayerDescs(flatbuffers::Offset<flatbuffers::Vector<const VisibleChunkLayerDesc *>> _visibleLayerDescs) { fbb_.AddOffset(SparseFeaturesChunkDesc::VT__VISIBLELAYERDESCS, _visibleLayerDescs); }
  SparseFeaturesChunkDescBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  SparseFeaturesChunkDescBuilder &operator=(const SparseFeaturesChunkDescBuilder &);
  flatbuffers::Offset<SparseFeaturesChunkDesc> Finish() {
    auto o = flatbuffers::Offset<SparseFeaturesChunkDesc>(fbb_.EndTable(start_, 6));
    return o;
  }
};

inline flatbuffers::Offset<SparseFeaturesChunkDesc> CreateSparseFeaturesChunkDesc(flatbuffers::FlatBufferBuilder &_fbb,
    const ogmaneo::schemas::int2 *_hiddenSize = 0,
    const ogmaneo::schemas::int2 *_chunkSize = 0,
    float _biasAlpha = 0.0f,
    float _gamma = 0.0f,
    const ogmaneo::schemas::float2 *_initWeightRange = 0,
    flatbuffers::Offset<flatbuffers::Vector<const VisibleChunkLayerDesc *>> _visibleLayerDescs = 0) {
  SparseFeaturesChunkDescBuilder builder_(_fbb);
  builder_.add__visibleLayerDescs(_visibleLayerDescs);
  builder_.add__initWeightRange(_initWeightRange);
  builder_.add__gamma(_gamma);
  builder_.add__biasAlpha(_biasAlpha);
  builder_.add__chunkSize(_chunkSize);
  builder_.add__hiddenSize(_hiddenSize);
  return builder_.Finish();
}

inline flatbuffers::Offset<SparseFeaturesChunkDesc> CreateSparseFeaturesChunkDescDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const ogmaneo::schemas::int2 *_hiddenSize = 0,
    const ogmaneo::schemas::int2 *_chunkSize = 0,
    float _biasAlpha = 0.0f,
    float _gamma = 0.0f,
    const ogmaneo::schemas::float2 *_initWeightRange = 0,
    const std::vector<const VisibleChunkLayerDesc *> *_visibleLayerDescs = nullptr) {
  return CreateSparseFeaturesChunkDesc(_fbb, _hiddenSize, _chunkSize, _biasAlpha, _gamma, _initWeightRange, _visibleLayerDescs ? _fbb.CreateVector<const VisibleChunkLayerDesc *>(*_visibleLayerDescs) : 0);
}

struct SparseFeaturesChunk FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__HIDDENSTATES = 4,
    VT__HIDDENBIASES = 6,
    VT__CHUNKWINNERS = 8,
    VT__HIDDENSIZE = 10,
    VT__CHUNKTOHIDDEN = 12,
    VT__CHUNKSIZE = 14,
    VT__HIDDENSUMMATIONTEMP = 16,
    VT__BIASALPHA = 18,
    VT__GAMMA = 20,
    VT__VISIBLELAYERDESCS = 22,
    VT__VISIBLELAYERS = 24
  };
  const ogmaneo::schemas::DoubleBuffer2D *_hiddenStates() const { return GetPointer<const ogmaneo::schemas::DoubleBuffer2D *>(VT__HIDDENSTATES); }
  ogmaneo::schemas::DoubleBuffer2D *mutable__hiddenStates() { return GetPointer<ogmaneo::schemas::DoubleBuffer2D *>(VT__HIDDENSTATES); }
  const ogmaneo::schemas::DoubleBuffer2D *_hiddenBiases() const { return GetPointer<const ogmaneo::schemas::DoubleBuffer2D *>(VT__HIDDENBIASES); }
  ogmaneo::schemas::DoubleBuffer2D *mutable__hiddenBiases() { return GetPointer<ogmaneo::schemas::DoubleBuffer2D *>(VT__HIDDENBIASES); }
  const ogmaneo::schemas::Image2D *_chunkWinners() const { return GetPointer<const ogmaneo::schemas::Image2D *>(VT__CHUNKWINNERS); }
  ogmaneo::schemas::Image2D *mutable__chunkWinners() { return GetPointer<ogmaneo::schemas::Image2D *>(VT__CHUNKWINNERS); }
  const ogmaneo::schemas::int2 *_hiddenSize() const { return GetStruct<const ogmaneo::schemas::int2 *>(VT__HIDDENSIZE); }
  ogmaneo::schemas::int2 *mutable__hiddenSize() { return GetStruct<ogmaneo::schemas::int2 *>(VT__HIDDENSIZE); }
  const ogmaneo::schemas::float2 *_chunkToHidden() const { return GetStruct<const ogmaneo::schemas::float2 *>(VT__CHUNKTOHIDDEN); }
  ogmaneo::schemas::float2 *mutable__chunkToHidden() { return GetStruct<ogmaneo::schemas::float2 *>(VT__CHUNKTOHIDDEN); }
  const ogmaneo::schemas::int2 *_chunkSize() const { return GetStruct<const ogmaneo::schemas::int2 *>(VT__CHUNKSIZE); }
  ogmaneo::schemas::int2 *mutable__chunkSize() { return GetStruct<ogmaneo::schemas::int2 *>(VT__CHUNKSIZE); }
  const ogmaneo::schemas::DoubleBuffer2D *_hiddenSummationTemp() const { return GetPointer<const ogmaneo::schemas::DoubleBuffer2D *>(VT__HIDDENSUMMATIONTEMP); }
  ogmaneo::schemas::DoubleBuffer2D *mutable__hiddenSummationTemp() { return GetPointer<ogmaneo::schemas::DoubleBuffer2D *>(VT__HIDDENSUMMATIONTEMP); }
  float _biasAlpha() const { return GetField<float>(VT__BIASALPHA, 0.0f); }
  bool mutate__biasAlpha(float __biasAlpha) { return SetField(VT__BIASALPHA, __biasAlpha); }
  float _gamma() const { return GetField<float>(VT__GAMMA, 0.0f); }
  bool mutate__gamma(float __gamma) { return SetField(VT__GAMMA, __gamma); }
  const flatbuffers::Vector<const VisibleChunkLayerDesc *> *_visibleLayerDescs() const { return GetPointer<const flatbuffers::Vector<const VisibleChunkLayerDesc *> *>(VT__VISIBLELAYERDESCS); }
  flatbuffers::Vector<const VisibleChunkLayerDesc *> *mutable__visibleLayerDescs() { return GetPointer<flatbuffers::Vector<const VisibleChunkLayerDesc *> *>(VT__VISIBLELAYERDESCS); }
  const flatbuffers::Vector<flatbuffers::Offset<VisibleChunkLayer>> *_visibleLayers() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<VisibleChunkLayer>> *>(VT__VISIBLELAYERS); }
  flatbuffers::Vector<flatbuffers::Offset<VisibleChunkLayer>> *mutable__visibleLayers() { return GetPointer<flatbuffers::Vector<flatbuffers::Offset<VisibleChunkLayer>> *>(VT__VISIBLELAYERS); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__HIDDENSTATES) &&
           verifier.VerifyTable(_hiddenStates()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__HIDDENBIASES) &&
           verifier.VerifyTable(_hiddenBiases()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__CHUNKWINNERS) &&
           verifier.VerifyTable(_chunkWinners()) &&
           VerifyField<ogmaneo::schemas::int2>(verifier, VT__HIDDENSIZE) &&
           VerifyField<ogmaneo::schemas::float2>(verifier, VT__CHUNKTOHIDDEN) &&
           VerifyField<ogmaneo::schemas::int2>(verifier, VT__CHUNKSIZE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__HIDDENSUMMATIONTEMP) &&
           verifier.VerifyTable(_hiddenSummationTemp()) &&
           VerifyField<float>(verifier, VT__BIASALPHA) &&
           VerifyField<float>(verifier, VT__GAMMA) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__VISIBLELAYERDESCS) &&
           verifier.Verify(_visibleLayerDescs()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__VISIBLELAYERS) &&
           verifier.Verify(_visibleLayers()) &&
           verifier.VerifyVectorOfTables(_visibleLayers()) &&
           verifier.EndTable();
  }
};

struct SparseFeaturesChunkBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__hiddenStates(flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _hiddenStates) { fbb_.AddOffset(SparseFeaturesChunk::VT__HIDDENSTATES, _hiddenStates); }
  void add__hiddenBiases(flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _hiddenBiases) { fbb_.AddOffset(SparseFeaturesChunk::VT__HIDDENBIASES, _hiddenBiases); }
  void add__chunkWinners(flatbuffers::Offset<ogmaneo::schemas::Image2D> _chunkWinners) { fbb_.AddOffset(SparseFeaturesChunk::VT__CHUNKWINNERS, _chunkWinners); }
  void add__hiddenSize(const ogmaneo::schemas::int2 *_hiddenSize) { fbb_.AddStruct(SparseFeaturesChunk::VT__HIDDENSIZE, _hiddenSize); }
  void add__chunkToHidden(const ogmaneo::schemas::float2 *_chunkToHidden) { fbb_.AddStruct(SparseFeaturesChunk::VT__CHUNKTOHIDDEN, _chunkToHidden); }
  void add__chunkSize(const ogmaneo::schemas::int2 *_chunkSize) { fbb_.AddStruct(SparseFeaturesChunk::VT__CHUNKSIZE, _chunkSize); }
  void add__hiddenSummationTemp(flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _hiddenSummationTemp) { fbb_.AddOffset(SparseFeaturesChunk::VT__HIDDENSUMMATIONTEMP, _hiddenSummationTemp); }
  void add__biasAlpha(float _biasAlpha) { fbb_.AddElement<float>(SparseFeaturesChunk::VT__BIASALPHA, _biasAlpha, 0.0f); }
  void add__gamma(float _gamma) { fbb_.AddElement<float>(SparseFeaturesChunk::VT__GAMMA, _gamma, 0.0f); }
  void add__visibleLayerDescs(flatbuffers::Offset<flatbuffers::Vector<const VisibleChunkLayerDesc *>> _visibleLayerDescs) { fbb_.AddOffset(SparseFeaturesChunk::VT__VISIBLELAYERDESCS, _visibleLayerDescs); }
  void add__visibleLayers(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<VisibleChunkLayer>>> _visibleLayers) { fbb_.AddOffset(SparseFeaturesChunk::VT__VISIBLELAYERS, _visibleLayers); }
  SparseFeaturesChunkBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  SparseFeaturesChunkBuilder &operator=(const SparseFeaturesChunkBuilder &);
  flatbuffers::Offset<SparseFeaturesChunk> Finish() {
    auto o = flatbuffers::Offset<SparseFeaturesChunk>(fbb_.EndTable(start_, 11));
    return o;
  }
};

inline flatbuffers::Offset<SparseFeaturesChunk> CreateSparseFeaturesChunk(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _hiddenStates = 0,
    flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _hiddenBiases = 0,
    flatbuffers::Offset<ogmaneo::schemas::Image2D> _chunkWinners = 0,
    const ogmaneo::schemas::int2 *_hiddenSize = 0,
    const ogmaneo::schemas::float2 *_chunkToHidden = 0,
    const ogmaneo::schemas::int2 *_chunkSize = 0,
    flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _hiddenSummationTemp = 0,
    float _biasAlpha = 0.0f,
    float _gamma = 0.0f,
    flatbuffers::Offset<flatbuffers::Vector<const VisibleChunkLayerDesc *>> _visibleLayerDescs = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<VisibleChunkLayer>>> _visibleLayers = 0) {
  SparseFeaturesChunkBuilder builder_(_fbb);
  builder_.add__visibleLayers(_visibleLayers);
  builder_.add__visibleLayerDescs(_visibleLayerDescs);
  builder_.add__gamma(_gamma);
  builder_.add__biasAlpha(_biasAlpha);
  builder_.add__hiddenSummationTemp(_hiddenSummationTemp);
  builder_.add__chunkSize(_chunkSize);
  builder_.add__chunkToHidden(_chunkToHidden);
  builder_.add__hiddenSize(_hiddenSize);
  builder_.add__chunkWinners(_chunkWinners);
  builder_.add__hiddenBiases(_hiddenBiases);
  builder_.add__hiddenStates(_hiddenStates);
  return builder_.Finish();
}

inline flatbuffers::Offset<SparseFeaturesChunk> CreateSparseFeaturesChunkDirect(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _hiddenStates = 0,
    flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _hiddenBiases = 0,
    flatbuffers::Offset<ogmaneo::schemas::Image2D> _chunkWinners = 0,
    const ogmaneo::schemas::int2 *_hiddenSize = 0,
    const ogmaneo::schemas::float2 *_chunkToHidden = 0,
    const ogmaneo::schemas::int2 *_chunkSize = 0,
    flatbuffers::Offset<ogmaneo::schemas::DoubleBuffer2D> _hiddenSummationTemp = 0,
    float _biasAlpha = 0.0f,
    float _gamma = 0.0f,
    const std::vector<const VisibleChunkLayerDesc *> *_visibleLayerDescs = nullptr,
    const std::vector<flatbuffers::Offset<VisibleChunkLayer>> *_visibleLayers = nullptr) {
  return CreateSparseFeaturesChunk(_fbb, _hiddenStates, _hiddenBiases, _chunkWinners, _hiddenSize, _chunkToHidden, _chunkSize, _hiddenSummationTemp, _biasAlpha, _gamma, _visibleLayerDescs ? _fbb.CreateVector<const VisibleChunkLayerDesc *>(*_visibleLayerDescs) : 0, _visibleLayers ? _fbb.CreateVector<flatbuffers::Offset<VisibleChunkLayer>>(*_visibleLayers) : 0);
}

}  // namespace schemas
}  // namespace ogmaneo

#endif  // FLATBUFFERS_GENERATED_SPARSEFEATURESCHUNK_OGMANEO_SCHEMAS_H_
