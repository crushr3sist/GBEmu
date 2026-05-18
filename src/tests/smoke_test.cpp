#include <gtest/gtest.h>

TEST(SmokeTest, BasicAssertions) {
  // expect two strings to not be equal
  EXPECT_STRNE("hello", "smoke");

  // Expect equality
  EXPECT_EQ(7 * 6, 42);
}
