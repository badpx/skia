

/**************************************************************************************************
 *** This file was autogenerated from GrDSLFPTest_ForStatement.fp; do not modify.
 **************************************************************************************************/
/* TODO(skia:11854): DSLCPPCodeGenerator is currently a work in progress. */
#include "GrDSLFPTest_ForStatement.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
#include "src/sksl/dsl/priv/DSLFPs.h"
#include "src/sksl/dsl/priv/DSLWriter.h"

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wcomma"
#endif

class GrGLSLDSLFPTest_ForStatement : public GrGLSLFragmentProcessor {
public:
    GrGLSLDSLFPTest_ForStatement() {}
    void emitCode(EmitArgs& args) override {
        const GrDSLFPTest_ForStatement& _outer = args.fFp.cast<GrDSLFPTest_ForStatement>();
        (void) _outer;

        using namespace SkSL::dsl;
        StartFragmentProcessor(this, &args);
[[maybe_unused]] const auto& colorWhite = _outer.colorWhite;
Var _colorWhite(kConst_Modifier, DSLType(kHalf4_Type), "colorWhite", Half4(colorWhite.fR, colorWhite.fG, colorWhite.fB, colorWhite.fA));
Declare(_colorWhite);
Var _color(kNo_Modifier, DSLType(kHalf4_Type), "color", _colorWhite);
Var _a(kNo_Modifier, DSLType(kHalf_Type), "a", 0.0f);
Var _r(kNo_Modifier, DSLType(kHalf_Type), "r", -5.0f);
Var _b(kNo_Modifier, DSLType(kHalf_Type), "b", 5.0f);
Declare(_color);
For(Declare(_a), _a <= 1.0f, ++_a, /*Body:*/ _color.w() = _a);
For(Declare(_r), _r < 5.0f, _r += 1.0f, /*Body:*/ Block(_color.x() = _r, If(_color.x() == 0.0f, /*Then:*/ Break())));
For(Declare(_b), _b >= 0.0f, _b -= 1.0f, /*Body:*/ Block(_color.z() = _b, If(_color.w() == 1.0f, /*Then:*/ Continue()), _color.y() = 0.0f));
Return(_color);
        EndFragmentProcessor();
    }
private:
    void onSetData(const GrGLSLProgramDataManager& pdman, const GrFragmentProcessor& _proc) override {
    }
};
std::unique_ptr<GrGLSLFragmentProcessor> GrDSLFPTest_ForStatement::onMakeProgramImpl() const {
    return std::make_unique<GrGLSLDSLFPTest_ForStatement>();
}
void GrDSLFPTest_ForStatement::onGetGLSLProcessorKey(const GrShaderCaps& caps, GrProcessorKeyBuilder* b) const {
    uint16_t red = SkFloatToHalf(colorWhite.fR);
    uint16_t green = SkFloatToHalf(colorWhite.fG);
    uint16_t blue = SkFloatToHalf(colorWhite.fB);
    uint16_t alpha = SkFloatToHalf(colorWhite.fA);
    b->add32(((uint32_t)red << 16) | green, "colorWhite.rg");
    b->add32(((uint32_t)blue << 16) | alpha, "colorWhite.ba");
}
bool GrDSLFPTest_ForStatement::onIsEqual(const GrFragmentProcessor& other) const {
    const GrDSLFPTest_ForStatement& that = other.cast<GrDSLFPTest_ForStatement>();
    (void) that;
    if (colorWhite != that.colorWhite) return false;
    return true;
}
GrDSLFPTest_ForStatement::GrDSLFPTest_ForStatement(const GrDSLFPTest_ForStatement& src)
: INHERITED(kGrDSLFPTest_ForStatement_ClassID, src.optimizationFlags())
, colorWhite(src.colorWhite) {
        this->cloneAndRegisterAllChildProcessors(src);
}
std::unique_ptr<GrFragmentProcessor> GrDSLFPTest_ForStatement::clone() const {
    return std::make_unique<GrDSLFPTest_ForStatement>(*this);
}
#if GR_TEST_UTILS
SkString GrDSLFPTest_ForStatement::onDumpInfo() const {
    return SkStringPrintf("(colorWhite=half4(%f, %f, %f, %f))", colorWhite.fR, colorWhite.fG, colorWhite.fB, colorWhite.fA);
}
#endif