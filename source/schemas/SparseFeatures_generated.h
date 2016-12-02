// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_SPARSEFEATURES_OGMANEO_SCHEMAS_H_
#define FLATBUFFERS_GENERATED_SPARSEFEATURES_OGMANEO_SCHEMAS_H_

#include "flatbuffers/flatbuffers.h"

#include "Helpers_generated.h"
#include "SparseFeaturesChunk_generated.h"
#include "SparseFeaturesDelay_generated.h"
#include "SparseFeaturesSTDP_generated.h"

namespace ogmaneo {
namespace schemas {

struct SparseFeaturesDesc;

struct SparseFeatures;

enum InputType {
  InputType__feedForward = 0,
  InputType__feedForwardRecurrent = 1,
  InputType_MIN = InputType__feedForward,
  InputType_MAX = InputType__feedForwardRecurrent
};

inline const char **EnumNamesInputType() {
  static const char *names[] = { "_feedForward", "_feedForwardRecurrent", nullptr };
  return names;
}

inline const char *EnumNameInputType(InputType e) { return EnumNamesInputType()[static_cast<int>(e)]; }

enum SparseFeaturesType {
  SparseFeaturesType_NONE = 0,
  SparseFeaturesType_SparseFeaturesChunk = 1,
  SparseFeaturesType_SparseFeaturesDelay = 2,
  SparseFeaturesType_SparseFeaturesSTDP = 3,
  SparseFeaturesType_MIN = SparseFeaturesType_NONE,
  SparseFeaturesType_MAX = SparseFeaturesType_SparseFeaturesSTDP
};

inline const char **EnumNamesSparseFeaturesType() {
  static const char *names[] = { "NONE", "SparseFeaturesChunk", "SparseFeaturesDelay", "SparseFeaturesSTDP", nullptr };
  return names;
}

inline const char *EnumNameSparseFeaturesType(SparseFeaturesType e) { return EnumNamesSparseFeaturesType()[static_cast<int>(e)]; }

template<typename T> struct SparseFeaturesTypeTraits {
  static const SparseFeaturesType enum_value = SparseFeaturesType_NONE;
};

template<> struct SparseFeaturesTypeTraits<ogmaneo::schemas::SparseFeaturesChunk> {
  static const SparseFeaturesType enum_value = SparseFeaturesType_SparseFeaturesChunk;
};

template<> struct SparseFeaturesTypeTraits<ogmaneo::schemas::SparseFeaturesDelay> {
  static const SparseFeaturesType enum_value = SparseFeaturesType_SparseFeaturesDelay;
};

template<> struct SparseFeaturesTypeTraits<ogmaneo::schemas::SparseFeaturesSTDP> {
  static const SparseFeaturesType enum_value = SparseFeaturesType_SparseFeaturesSTDP;
};

inline bool VerifySparseFeaturesType(flatbuffers::Verifier &verifier, const void *union_obj, SparseFeaturesType type);

struct SparseFeaturesDesc FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__NAME = 4,
    VT__INPUTTYPE = 6
  };
  const flatbuffers::String *_name() const { return GetPointer<const flatbuffers::String *>(VT__NAME); }
  flatbuffers::String *mutable__name() { return GetPointer<flatbuffers::String *>(VT__NAME); }
  InputType _inputType() const { return static_cast<InputType>(GetField<int8_t>(VT__INPUTTYPE, 0)); }
  bool mutate__inputType(InputType __inputType) { return SetField(VT__INPUTTYPE, static_cast<int8_t>(__inputType)); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__NAME) &&
           verifier.Verify(_name()) &&
           VerifyField<int8_t>(verifier, VT__INPUTTYPE) &&
           verifier.EndTable();
  }
};

struct SparseFeaturesDescBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__name(flatbuffers::Offset<flatbuffers::String> _name) { fbb_.AddOffset(SparseFeaturesDesc::VT__NAME, _name); }
  void add__inputType(InputType _inputType) { fbb_.AddElement<int8_t>(SparseFeaturesDesc::VT__INPUTTYPE, static_cast<int8_t>(_inputType), 0); }
  SparseFeaturesDescBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  SparseFeaturesDescBuilder &operator=(const SparseFeaturesDescBuilder &);
  flatbuffers::Offset<SparseFeaturesDesc> Finish() {
    auto o = flatbuffers::Offset<SparseFeaturesDesc>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<SparseFeaturesDesc> CreateSparseFeaturesDesc(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> _name = 0,
    InputType _inputType = InputType__feedForward) {
  SparseFeaturesDescBuilder builder_(_fbb);
  builder_.add__name(_name);
  builder_.add__inputType(_inputType);
  return builder_.Finish();
}

inline flatbuffers::Offset<SparseFeaturesDesc> CreateSparseFeaturesDescDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const char *_name = nullptr,
    InputType _inputType = InputType__feedForward) {
  return CreateSparseFeaturesDesc(_fbb, _name ? _fbb.CreateString(_name) : 0, _inputType);
}

struct SparseFeatures FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT__SF_TYPE = 4,
    VT__SF = 6
  };
  SparseFeaturesType _sf_type() const { return static_cast<SparseFeaturesType>(GetField<uint8_t>(VT__SF_TYPE, 0)); }
  bool mutate__sf_type(SparseFeaturesType __sf_type) { return SetField(VT__SF_TYPE, static_cast<uint8_t>(__sf_type)); }
  const void *_sf() const { return GetPointer<const void *>(VT__SF); }
  void *mutable__sf() { return GetPointer<void *>(VT__SF); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT__SF_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT__SF) &&
           VerifySparseFeaturesType(verifier, _sf(), _sf_type()) &&
           verifier.EndTable();
  }
};

struct SparseFeaturesBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add__sf_type(SparseFeaturesType _sf_type) { fbb_.AddElement<uint8_t>(SparseFeatures::VT__SF_TYPE, static_cast<uint8_t>(_sf_type), 0); }
  void add__sf(flatbuffers::Offset<void> _sf) { fbb_.AddOffset(SparseFeatures::VT__SF, _sf); }
  SparseFeaturesBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  SparseFeaturesBuilder &operator=(const SparseFeaturesBuilder &);
  flatbuffers::Offset<SparseFeatures> Finish() {
    auto o = flatbuffers::Offset<SparseFeatures>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<SparseFeatures> CreateSparseFeatures(flatbuffers::FlatBufferBuilder &_fbb,
    SparseFeaturesType _sf_type = SparseFeaturesType_NONE,
    flatbuffers::Offset<void> _sf = 0) {
  SparseFeaturesBuilder builder_(_fbb);
  builder_.add__sf(_sf);
  builder_.add__sf_type(_sf_type);
  return builder_.Finish();
}

inline bool VerifySparseFeaturesType(flatbuffers::Verifier &verifier, const void *union_obj, SparseFeaturesType type) {
  switch (type) {
    case SparseFeaturesType_NONE: return true;
    case SparseFeaturesType_SparseFeaturesChunk: return verifier.VerifyTable(reinterpret_cast<const ogmaneo::schemas::SparseFeaturesChunk *>(union_obj));
    case SparseFeaturesType_SparseFeaturesDelay: return verifier.VerifyTable(reinterpret_cast<const ogmaneo::schemas::SparseFeaturesDelay *>(union_obj));
    case SparseFeaturesType_SparseFeaturesSTDP: return verifier.VerifyTable(reinterpret_cast<const ogmaneo::schemas::SparseFeaturesSTDP *>(union_obj));
    default: return false;
  }
}

}  // namespace schemas
}  // namespace ogmaneo

#endif  // FLATBUFFERS_GENERATED_SPARSEFEATURES_OGMANEO_SCHEMAS_H_
