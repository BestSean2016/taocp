#include "gtest/gtest.h"
#include "taocp.h"

TEST(get_amount_combi, get_amount_combi) {
  EXPECT_EQ(get_amount_combi(6, 3), (uint32)20);
  EXPECT_EQ(get_amount_combi(7, 4),
            (uint32)((7 * 6 * 5 * 4) / (4 * 3 * 2 * 1)));
}

TEST(lexicographic_combinations_L, lexicographic_combinations_L) {
  // lexicographic_combinations_L(6, 3, show_combination, stdout);
  uint8 C6_3[] = {0, 1, 2, 0, 1, 3, 0, 2, 3, 1, 2, 3, 0, 1, 4, 0, 2, 4, 1, 2,
                  4, 0, 3, 4, 1, 3, 4, 2, 3, 4, 0, 1, 5, 0, 2, 5, 1, 2, 5, 0,
                  3, 5, 1, 3, 5, 2, 3, 5, 0, 4, 5, 1, 4, 5, 2, 4, 5, 3, 4, 5};

  uint8 result6_3[20 * 3];
  lexicographic_combinations_L(6, 3, get_combination, result6_3);
  EXPECT_EQ(memcmp(result6_3, C6_3, sizeof(result6_3)), 0);

  // lexicographic_combinations_L(7, 4, show_combination, stdout);
  uint8 C7_4[] = {0, 1, 2, 3, 0, 1, 2, 4, 0, 1, 3, 4, 0, 2, 3, 4, 1, 2, 3, 4,
                  0, 1, 2, 5, 0, 1, 3, 5, 0, 2, 3, 5, 1, 2, 3, 5, 0, 1, 4, 5,
                  0, 2, 4, 5, 1, 2, 4, 5, 0, 3, 4, 5, 1, 3, 4, 5, 2, 3, 4, 5,
                  0, 1, 2, 6, 0, 1, 3, 6, 0, 2, 3, 6, 1, 2, 3, 6, 0, 1, 4, 6,
                  0, 2, 4, 6, 1, 2, 4, 6, 0, 3, 4, 6, 1, 3, 4, 6, 2, 3, 4, 6,
                  0, 1, 5, 6, 0, 2, 5, 6, 1, 2, 5, 6, 0, 3, 5, 6, 1, 3, 5, 6,
                  2, 3, 5, 6, 0, 4, 5, 6, 1, 4, 5, 6, 2, 4, 5, 6, 3, 4, 5, 6};

  uint8 result7_4[35 * 4];
  lexicographic_combinations_L(7, 4, get_combination, result7_4);
  EXPECT_EQ(memcmp(result7_4, C7_4, sizeof(result7_4)), 0);
}

TEST(lexicographic_combinations_T, lexicographic_combinations_T) {
  //lexicographic_combinations_T(6, 3, show_combination, stdout);
  //
  // uint8 C6_3[] = {0, 1, 2, 0, 1, 3, 0, 2, 3, 1, 2, 3, 0, 1, 4, 0, 2, 4, 1, 2,
  //                4, 0, 3, 4, 1, 3, 4, 2, 3, 4, 0, 1, 5, 0, 2, 5, 1, 2, 5, 0,
  //                3, 5, 1, 3, 5, 2, 3, 5, 0, 4, 5, 1, 4, 5, 2, 4, 5, 3, 4, 5};
  // uint8 result6_3[20 * 3];
  // lexicographic_combinations_T(6, 3, get_combination, result6_3);
  // EXPECT_EQ(memcmp(result6_3, C6_3, sizeof(result6_3)), 0);
  //
  ////lexicographic_combinations_L(7, 4, show_combination, stdout);
  // uint8 C7_4[] = {0, 1, 2, 3, 0, 1, 2, 4, 0, 1, 3, 4, 0, 2, 3, 4, 1, 2, 3, 4,
  //                0, 1, 2, 5, 0, 1, 3, 5, 0, 2, 3, 5, 1, 2, 3, 5, 0, 1, 4, 5,
  //                0, 2, 4, 5, 1, 2, 4, 5, 0, 3, 4, 5, 1, 3, 4, 5, 2, 3, 4, 5,
  //                0, 1, 2, 6, 0, 1, 3, 6, 0, 2, 3, 6, 1, 2, 3, 6, 0, 1, 4, 6,
  //                0, 2, 4, 6, 1, 2, 4, 6, 0, 3, 4, 6, 1, 3, 4, 6, 2, 3, 4, 6,
  //                0, 1, 5, 6, 0, 2, 5, 6, 1, 2, 5, 6, 0, 3, 5, 6, 1, 3, 5, 6,
  //                2, 3, 5, 6, 0, 4, 5, 6, 1, 4, 5, 6, 2, 4, 5, 6, 3, 4, 5, 6};
  //
  // uint8 result7_4[35 * 4];
  // lexicographic_combinations_T(7, 4, get_combination, result7_4);
  // EXPECT_EQ(memcmp(result7_4, C7_4, sizeof(result7_4)), 0);
}
