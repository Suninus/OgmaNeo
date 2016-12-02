// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_ARCHITECT_OGMANEO_SCHEMAS_H_
#define FLATBUFFERS_GENERATED_ARCHITECT_OGMANEO_SCHEMAS_H_

#include "flatbuffers/flatbuffers.h"

#include "Helpers_generated.h"
#include "SparseFeatures_generated.h"
#include "SparseFeaturesChunk_generated.h"
#include "SparseFeaturesDelay_generated.h"
#include "SparseFeaturesSTDP_generated.h"

namespace ogmaneo {
namespace schemas {

struct Parameter;

struct ParameterModifier;

struct InputLayer;

struct ActionLayer;

struct HigherLayer;

struct Architect;

enum SparseFeaturesTypeEnum {
  SparseFeaturesTypeEnum__stdp = 0,
  SparseFeaturesTypeEnum__delay = 1,
  SparseFeaturesTypeEnum__chunk = 2,
  SparseFeaturesTypeEnum_MIN = SparseFeaturesTypeEnum__stdp,
  SparseFeaturesTypeEnum_MAX = SparseFeaturesTypeEnum__chunk
};

inline const char **EnumNamesSparseFeaturesTypeEnum() {
  static const char *names[] = { "_stdp", "_delay", "_chunk", nullptr };
  return names;
}

inline const char *EnumNameSparseFeaturesTypeEnum(SparseFeaturesTypeEnum e) { return EnumNamesSparseFeaturesTypeEnum()[static_cast<int>(e)]; }

struct Parameter FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__KEY = 4,
    VT__VALUE = 6
  };
  const flatbuffers::String *_key() const { return GetPointer<const flatbuffers::String *>(VT__KEY); }
  flatbuffers::String *mutable__key() { return GetPointer<flatbuffers::String *>(VT__KEY); }
  const flatbuffers::String *_value() const { return GetPointer<const flatbuffers::String *>(VT__VALUE); }
  flatbuffers::String *mutable__value() { return GetPointer<flatbuffers::String *>(VT__VALUE); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__KEY) &&
           verifier.Verify(_key()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__VALUE) &&
           verifier.Verify(_value()) &&
           verifier.EndTable();
  }
};

struct ParameterBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__key(flatbuffers::Offset<flatbuffers::String> _key) { fbb_.AddOffset(Parameter::VT__KEY, _key); }
  void add__value(flatbuffers::Offset<flatbuffers::String> _value) { fbb_.AddOffset(Parameter::VT__VALUE, _value); }
  ParameterBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ParameterBuilder &operator=(const ParameterBuilder &);
  flatbuffers::Offset<Parameter> Finish() {
    auto o = flatbuffers::Offset<Parameter>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<Parameter> CreateParameter(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> _key = 0,
    flatbuffers::Offset<flatbuffers::String> _value = 0) {
  ParameterBuilder builder_(_fbb);
  builder_.add__value(_value);
  builder_.add__key(_key);
  return builder_.Finish();
}

inline flatbuffers::Offset<Parameter> CreateParameterDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const char *_key = nullptr,
    const char *_value = nullptr) {
  return CreateParameter(_fbb, _key ? _fbb.CreateString(_key) : 0, _value ? _fbb.CreateString(_value) : 0);
}

struct ParameterModifier FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__TARGET = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<Parameter>> *_target() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Parameter>> *>(VT__TARGET); }
  flatbuffers::Vector<flatbuffers::Offset<Parameter>> *mutable__target() { return GetPointer<flatbuffers::Vector<flatbuffers::Offset<Parameter>> *>(VT__TARGET); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__TARGET) &&
           verifier.Verify(_target()) &&
           verifier.VerifyVectorOfTables(_target()) &&
           verifier.EndTable();
  }
};

struct ParameterModifierBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__target(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Parameter>>> _target) { fbb_.AddOffset(ParameterModifier::VT__TARGET, _target); }
  ParameterModifierBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ParameterModifierBuilder &operator=(const ParameterModifierBuilder &);
  flatbuffers::Offset<ParameterModifier> Finish() {
    auto o = flatbuffers::Offset<ParameterModifier>(fbb_.EndTable(start_, 1));
    return o;
  }
};

inline flatbuffers::Offset<ParameterModifier> CreateParameterModifier(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Parameter>>> _target = 0) {
  ParameterModifierBuilder builder_(_fbb);
  builder_.add__target(_target);
  return builder_.Finish();
}

inline flatbuffers::Offset<ParameterModifier> CreateParameterModifierDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<Parameter>> *_target = nullptr) {
  return CreateParameterModifier(_fbb, _target ? _fbb.CreateVector<flatbuffers::Offset<Parameter>>(*_target) : 0);
}

struct InputLayer FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__SIZE = 4,
    VT__PARAMS = 6
  };
  const ogmaneo::schemas::Vec2i *_size() const { return GetStruct<const ogmaneo::schemas::Vec2i *>(VT__SIZE); }
  ogmaneo::schemas::Vec2i *mutable__size() { return GetStruct<ogmaneo::schemas::Vec2i *>(VT__SIZE); }
  const flatbuffers::Vector<flatbuffers::Offset<Parameter>> *_params() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Parameter>> *>(VT__PARAMS); }
  flatbuffers::Vector<flatbuffers::Offset<Parameter>> *mutable__params() { return GetPointer<flatbuffers::Vector<flatbuffers::Offset<Parameter>> *>(VT__PARAMS); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<ogmaneo::schemas::Vec2i>(verifier, VT__SIZE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__PARAMS) &&
           verifier.Verify(_params()) &&
           verifier.VerifyVectorOfTables(_params()) &&
           verifier.EndTable();
  }
};

struct InputLayerBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__size(const ogmaneo::schemas::Vec2i *_size) { fbb_.AddStruct(InputLayer::VT__SIZE, _size); }
  void add__params(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Parameter>>> _params) { fbb_.AddOffset(InputLayer::VT__PARAMS, _params); }
  InputLayerBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  InputLayerBuilder &operator=(const InputLayerBuilder &);
  flatbuffers::Offset<InputLayer> Finish() {
    auto o = flatbuffers::Offset<InputLayer>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<InputLayer> CreateInputLayer(flatbuffers::FlatBufferBuilder &_fbb,
    const ogmaneo::schemas::Vec2i *_size = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Parameter>>> _params = 0) {
  InputLayerBuilder builder_(_fbb);
  builder_.add__params(_params);
  builder_.add__size(_size);
  return builder_.Finish();
}

inline flatbuffers::Offset<InputLayer> CreateInputLayerDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const ogmaneo::schemas::Vec2i *_size = 0,
    const std::vector<flatbuffers::Offset<Parameter>> *_params = nullptr) {
  return CreateInputLayer(_fbb, _size, _params ? _fbb.CreateVector<flatbuffers::Offset<Parameter>>(*_params) : 0);
}

struct ActionLayer FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__SIZE = 4,
    VT__TILESIZE = 6,
    VT__PARAMS = 8
  };
  const ogmaneo::schemas::Vec2i *_size() const { return GetStruct<const ogmaneo::schemas::Vec2i *>(VT__SIZE); }
  ogmaneo::schemas::Vec2i *mutable__size() { return GetStruct<ogmaneo::schemas::Vec2i *>(VT__SIZE); }
  const ogmaneo::schemas::Vec2i *_tileSize() const { return GetStruct<const ogmaneo::schemas::Vec2i *>(VT__TILESIZE); }
  ogmaneo::schemas::Vec2i *mutable__tileSize() { return GetStruct<ogmaneo::schemas::Vec2i *>(VT__TILESIZE); }
  const flatbuffers::Vector<flatbuffers::Offset<Parameter>> *_params() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Parameter>> *>(VT__PARAMS); }
  flatbuffers::Vector<flatbuffers::Offset<Parameter>> *mutable__params() { return GetPointer<flatbuffers::Vector<flatbuffers::Offset<Parameter>> *>(VT__PARAMS); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<ogmaneo::schemas::Vec2i>(verifier, VT__SIZE) &&
           VerifyField<ogmaneo::schemas::Vec2i>(verifier, VT__TILESIZE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__PARAMS) &&
           verifier.Verify(_params()) &&
           verifier.VerifyVectorOfTables(_params()) &&
           verifier.EndTable();
  }
};

struct ActionLayerBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__size(const ogmaneo::schemas::Vec2i *_size) { fbb_.AddStruct(ActionLayer::VT__SIZE, _size); }
  void add__tileSize(const ogmaneo::schemas::Vec2i *_tileSize) { fbb_.AddStruct(ActionLayer::VT__TILESIZE, _tileSize); }
  void add__params(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Parameter>>> _params) { fbb_.AddOffset(ActionLayer::VT__PARAMS, _params); }
  ActionLayerBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ActionLayerBuilder &operator=(const ActionLayerBuilder &);
  flatbuffers::Offset<ActionLayer> Finish() {
    auto o = flatbuffers::Offset<ActionLayer>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<ActionLayer> CreateActionLayer(flatbuffers::FlatBufferBuilder &_fbb,
    const ogmaneo::schemas::Vec2i *_size = 0,
    const ogmaneo::schemas::Vec2i *_tileSize = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Parameter>>> _params = 0) {
  ActionLayerBuilder builder_(_fbb);
  builder_.add__params(_params);
  builder_.add__tileSize(_tileSize);
  builder_.add__size(_size);
  return builder_.Finish();
}

inline flatbuffers::Offset<ActionLayer> CreateActionLayerDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const ogmaneo::schemas::Vec2i *_size = 0,
    const ogmaneo::schemas::Vec2i *_tileSize = 0,
    const std::vector<flatbuffers::Offset<Parameter>> *_params = nullptr) {
  return CreateActionLayer(_fbb, _size, _tileSize, _params ? _fbb.CreateVector<flatbuffers::Offset<Parameter>>(*_params) : 0);
}

struct HigherLayer FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__SIZE = 4,
    VT__TYPE = 6,
    VT__PARAMS = 8
  };
  const ogmaneo::schemas::Vec2i *_size() const { return GetStruct<const ogmaneo::schemas::Vec2i *>(VT__SIZE); }
  ogmaneo::schemas::Vec2i *mutable__size() { return GetStruct<ogmaneo::schemas::Vec2i *>(VT__SIZE); }
  SparseFeaturesTypeEnum _type() const { return static_cast<SparseFeaturesTypeEnum>(GetField<int8_t>(VT__TYPE, 0)); }
  bool mutate__type(SparseFeaturesTypeEnum __type) { return SetField(VT__TYPE, static_cast<int8_t>(__type)); }
  const flatbuffers::Vector<flatbuffers::Offset<Parameter>> *_params() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Parameter>> *>(VT__PARAMS); }
  flatbuffers::Vector<flatbuffers::Offset<Parameter>> *mutable__params() { return GetPointer<flatbuffers::Vector<flatbuffers::Offset<Parameter>> *>(VT__PARAMS); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<ogmaneo::schemas::Vec2i>(verifier, VT__SIZE) &&
           VerifyField<int8_t>(verifier, VT__TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__PARAMS) &&
           verifier.Verify(_params()) &&
           verifier.VerifyVectorOfTables(_params()) &&
           verifier.EndTable();
  }
};

struct HigherLayerBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__size(const ogmaneo::schemas::Vec2i *_size) { fbb_.AddStruct(HigherLayer::VT__SIZE, _size); }
  void add__type(SparseFeaturesTypeEnum _type) { fbb_.AddElement<int8_t>(HigherLayer::VT__TYPE, static_cast<int8_t>(_type), 0); }
  void add__params(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Parameter>>> _params) { fbb_.AddOffset(HigherLayer::VT__PARAMS, _params); }
  HigherLayerBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  HigherLayerBuilder &operator=(const HigherLayerBuilder &);
  flatbuffers::Offset<HigherLayer> Finish() {
    auto o = flatbuffers::Offset<HigherLayer>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<HigherLayer> CreateHigherLayer(flatbuffers::FlatBufferBuilder &_fbb,
    const ogmaneo::schemas::Vec2i *_size = 0,
    SparseFeaturesTypeEnum _type = SparseFeaturesTypeEnum__stdp,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Parameter>>> _params = 0) {
  HigherLayerBuilder builder_(_fbb);
  builder_.add__params(_params);
  builder_.add__size(_size);
  builder_.add__type(_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<HigherLayer> CreateHigherLayerDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const ogmaneo::schemas::Vec2i *_size = 0,
    SparseFeaturesTypeEnum _type = SparseFeaturesTypeEnum__stdp,
    const std::vector<flatbuffers::Offset<Parameter>> *_params = nullptr) {
  return CreateHigherLayer(_fbb, _size, _type, _params ? _fbb.CreateVector<flatbuffers::Offset<Parameter>>(*_params) : 0);
}

struct Architect FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__INPUTLAYERS = 4,
    VT__ACTIONLAYERS = 6,
    VT__HIGHERLAYERS = 8
  };
  const flatbuffers::Vector<flatbuffers::Offset<InputLayer>> *_inputLayers() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<InputLayer>> *>(VT__INPUTLAYERS); }
  flatbuffers::Vector<flatbuffers::Offset<InputLayer>> *mutable__inputLayers() { return GetPointer<flatbuffers::Vector<flatbuffers::Offset<InputLayer>> *>(VT__INPUTLAYERS); }
  const flatbuffers::Vector<flatbuffers::Offset<ActionLayer>> *_actionLayers() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ActionLayer>> *>(VT__ACTIONLAYERS); }
  flatbuffers::Vector<flatbuffers::Offset<ActionLayer>> *mutable__actionLayers() { return GetPointer<flatbuffers::Vector<flatbuffers::Offset<ActionLayer>> *>(VT__ACTIONLAYERS); }
  const flatbuffers::Vector<flatbuffers::Offset<HigherLayer>> *_higherLayers() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<HigherLayer>> *>(VT__HIGHERLAYERS); }
  flatbuffers::Vector<flatbuffers::Offset<HigherLayer>> *mutable__higherLayers() { return GetPointer<flatbuffers::Vector<flatbuffers::Offset<HigherLayer>> *>(VT__HIGHERLAYERS); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__INPUTLAYERS) &&
           verifier.Verify(_inputLayers()) &&
           verifier.VerifyVectorOfTables(_inputLayers()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__ACTIONLAYERS) &&
           verifier.Verify(_actionLayers()) &&
           verifier.VerifyVectorOfTables(_actionLayers()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__HIGHERLAYERS) &&
           verifier.Verify(_higherLayers()) &&
           verifier.VerifyVectorOfTables(_higherLayers()) &&
           verifier.EndTable();
  }
};

struct ArchitectBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__inputLayers(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<InputLayer>>> _inputLayers) { fbb_.AddOffset(Architect::VT__INPUTLAYERS, _inputLayers); }
  void add__actionLayers(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ActionLayer>>> _actionLayers) { fbb_.AddOffset(Architect::VT__ACTIONLAYERS, _actionLayers); }
  void add__higherLayers(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<HigherLayer>>> _higherLayers) { fbb_.AddOffset(Architect::VT__HIGHERLAYERS, _higherLayers); }
  ArchitectBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ArchitectBuilder &operator=(const ArchitectBuilder &);
  flatbuffers::Offset<Architect> Finish() {
    auto o = flatbuffers::Offset<Architect>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<Architect> CreateArchitect(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<InputLayer>>> _inputLayers = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ActionLayer>>> _actionLayers = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<HigherLayer>>> _higherLayers = 0) {
  ArchitectBuilder builder_(_fbb);
  builder_.add__higherLayers(_higherLayers);
  builder_.add__actionLayers(_actionLayers);
  builder_.add__inputLayers(_inputLayers);
  return builder_.Finish();
}

inline flatbuffers::Offset<Architect> CreateArchitectDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<InputLayer>> *_inputLayers = nullptr,
    const std::vector<flatbuffers::Offset<ActionLayer>> *_actionLayers = nullptr,
    const std::vector<flatbuffers::Offset<HigherLayer>> *_higherLayers = nullptr) {
  return CreateArchitect(_fbb, _inputLayers ? _fbb.CreateVector<flatbuffers::Offset<InputLayer>>(*_inputLayers) : 0, _actionLayers ? _fbb.CreateVector<flatbuffers::Offset<ActionLayer>>(*_actionLayers) : 0, _higherLayers ? _fbb.CreateVector<flatbuffers::Offset<HigherLayer>>(*_higherLayers) : 0);
}

inline const ogmaneo::schemas::Architect *GetArchitect(const void *buf) {
  return flatbuffers::GetRoot<ogmaneo::schemas::Architect>(buf);
}

inline Architect *GetMutableArchitect(void *buf) {
  return flatbuffers::GetMutableRoot<Architect>(buf);
}

inline const char *ArchitectIdentifier() {
  return "OARC";
}

inline bool ArchitectBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(buf, ArchitectIdentifier());
}

inline bool VerifyArchitectBuffer(flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<ogmaneo::schemas::Architect>(ArchitectIdentifier());
}

inline const char *ArchitectExtension() { return "oar"; }

inline void FinishArchitectBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<ogmaneo::schemas::Architect> root) {
  fbb.Finish(root, ArchitectIdentifier());
}

}  // namespace schemas
}  // namespace ogmaneo

#endif  // FLATBUFFERS_GENERATED_ARCHITECT_OGMANEO_SCHEMAS_H_
