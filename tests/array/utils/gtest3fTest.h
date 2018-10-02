#include "gtest/gtest.h"

extern "C" {
  #include "constants/universalConsts.h"
}

#define SCALAR float

const uint ARRAY_SIZE_X = 11;
const uint ARRAY_SIZE_Y = 18;
const uint ARRAY_SIZE_Z = 5;

class Array3fTest : public ::testing::Test {
public:
  uint IterAbsOffset(array3f::iterator iter) {
    return iter.i() + ARRAY_SIZE_X * iter.j() + ARRAY_SIZE_X * ARRAY_SIZE_Y * iter.k();
  }

protected:
  virtual void SetUp() {
    arr.resize(ARRAY_SIZE_X, ARRAY_SIZE_Y, ARRAY_SIZE_Z, true);
    arr2.resize(ARRAY_SIZE_X, ARRAY_SIZE_Y, ARRAY_SIZE_Z, true);

    arr.set_rate(ZFP_RATE_PARAM_BITS);
    arr2.set_rate(ZFP_RATE_PARAM_BITS);

    offsetX = 5;
    viewLenX = 3;
    EXPECT_LT(offsetX + viewLenX, arr.size_x());

    offsetY = 1;
    viewLenY = 3;
    EXPECT_LT(offsetY + viewLenY, arr.size_y());

    offsetZ = 0;
    viewLenZ = 2;
    EXPECT_LT(offsetZ + viewLenZ, arr.size_z());
  }

  static array3f arr, arr2;
  static array3f::pointer ptr, ptr2;
  static array3f::iterator iter, iter2;
  static uint offsetX, offsetY, offsetZ;
  static uint viewLenX, viewLenY, viewLenZ;
};

array3f Array3fTest::arr(ARRAY_SIZE_X, ARRAY_SIZE_Y, ARRAY_SIZE_Z, ZFP_RATE_PARAM_BITS);
array3f Array3fTest::arr2(ARRAY_SIZE_X, ARRAY_SIZE_Y, ARRAY_SIZE_Z, ZFP_RATE_PARAM_BITS);
array3f::pointer Array3fTest::ptr, Array3fTest::ptr2;
array3f::iterator Array3fTest::iter, Array3fTest::iter2;
uint Array3fTest::offsetX, Array3fTest::offsetY, Array3fTest::offsetZ;
uint Array3fTest::viewLenX, Array3fTest::viewLenY, Array3fTest::viewLenZ;
