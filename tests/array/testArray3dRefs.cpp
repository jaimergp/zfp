#include "array/zfparray3.h"
using namespace zfp;

extern "C" {
  #include "utils/hash64.h"
  #include "utils/rand64.h"
}

#define ARRAY_DIMS_SCALAR_TEST Array3dTest
#define ARRAY_DIMS_SCALAR_TEST_REFS Array3dTestRefs

#include "utils/gtest3dTest.h"

#include "testArrayRefsBase.cpp"
#include "testArray3RefsBase.cpp"
