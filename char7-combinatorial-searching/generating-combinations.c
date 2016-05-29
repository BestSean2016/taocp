#include "taocp.h"

int show_combination(const uint8 *n_tuples, const uint8 n, const uint8 t,
                     const uint32 index, const dataptr data) {
  (void)n;

  FILE *fpout = (FILE *)data;
  uint32 i;
  fprintf(fpout, "%d: ", index + 1);
  for (i = 0; i < t; ++i)
    fprintf(fpout, "%u, ", (uint)n_tuples[i]);
  fprintf(fpout, "\n");

  return (0);
}

int get_combination(const uint8 *n_tuples, const uint8 n, const uint8 t,
                    const uint32 index, const dataptr userdata) {
  uint8* buf;
  (void)n;

  if (!userdata) return (-3);

  buf = (uint8 *)userdata + index * t;
  memcpy(buf, n_tuples, t);
  return (0);
}

uint get_amount_combi(const uint n, const uint t) {
  uint32 p1 = 1, p2 = 1;
  uint32 i;

  for (i = n; i > n - t; i--)
    p1 *= i;

  for (i = 2; i <= t; i++)
    p2 *= i;

  return p1 / p2;
}

int lexicographic_combinations_L(const uint8 n, const uint8 t,
                                 visit_callback visit,
                                 const dataptr userdata) {
  uint j, i;
  uint8* C;
  int result = 0;

  if (t > n) return -1;
  if (visit == NULL) return -2;

  i = 0;
  C = (uint8 *)calloc(sizeof(uint8), t + 3);

  // L1, initialize
  for (j = 1; j <= t; ++j)
    C[j] = j - 1;
  C[t + 1] = n;
  C[t + 2] = 0;

L2:
  // L2, visit
  result = visit(C + 1, n, t, i++, userdata);
  if (result)
      goto L6;

  // L3, Find j
  j = 1;
  while (C[j] + 1 == C[j + 1])
    C[j] = j - 1, ++j;

  // L4 and L5. Increase Cj, until j > t
  if (j <= t) {
    C[j]++;
    goto L2;
  }

L6:
  free(C);
  return result;
}

int lexicographic_combinations_T(const uint8 n, const uint8 t,
                                  visit_callback visit,
                                  const dataptr userdata) {
  int j, x, result;
  uint32 i;
  uint8  *C;

  if (t > n) return (-1);
  if (visit == 0) return (-2);

  C= (uint8 *)calloc(sizeof(uint8), t + 3);
  j = x = result = 0, i = 0;

  // T1, initialize
  // Set Cj <- j -1 for 1 <= j <= t; then set Ct+1 <- n, Ct+2 <- 0 and j <- t
  // +----------------------------------------------------+
  // |  C0 |  C1 | C2  | C3 | ...   |   Ct  | Ct+1 | Ct+2 |
  // +----------------------------------------------------+
  // |  NA |  0  |  1  |  2 | ...   | t - 1 |   n  |  0   |
  // +----------------------------------------------------+
  for (j = 1; j <= t; ++j)
    C[j] = j - 1;
  C[t + 1] = n, C[t + 2] = 0, j = t;

T2:
  // T2, visit
  result = visit(C + 1, n, t, i++, userdata); // visit
  if(result) goto T7;

  // if j > 0, set x <- j and got step T6
  if (j > 0) {
    x = j;
    goto T6;
  }

  // T3, Easy case?
  // if C1 + 1 < C2, set C1 <- C1 + 1 and return to T2, Otherwise set j <- 2
  if (C[1] + 1 < C[2]) {
    ++(C[1]);
    goto T2;
  } else
    j = 2;

  // T4, Find j
  // Set Cj-1 <- j-1 and x <- (Cj)+1. If x = Cj+1, set j<-j+1 and repeat this
  // step until x < Cj+1
  C[j - 1] = j - 1;
  x = C[j] + 1;
  if (x == C[j + 1]) {
    while (x >= C[j + 1])
      ++j;
  }

  // T5, it's done?
  // Terminate the algorithm if j > t.
  if (j > t)
    goto T7;

T6:
  // T6, Increase Cj, set Cj <- x, j <- j-1, and return to T2
  C[j] = x;
  --j;
  goto T2;

// T7, end.
T7:
  free(C);
  return result;
}
