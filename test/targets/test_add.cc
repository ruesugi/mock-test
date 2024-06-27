#include <gtest/gtest.h>

#ifdef __cplusplus
extern "C" {
#endif
#include "add.h"
#ifdef __cplusplus
}
#endif
TEST(AddTest, ShouldReturn8) {
  // Expect equality.
  EXPECT_EQ(Add(3, 5), 8);
}
