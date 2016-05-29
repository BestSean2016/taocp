#ifndef __TAOCP_H_INCLUDE__
#define __TAOCP_H_INCLUDE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <ctype.h>
#include <sys/types.h>

typedef unsigned int uint32;
typedef u_int64_t uint64;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef int     int32;
typedef int64_t int64;
typedef short   int16;
typedef char    int8;
typedef void   *dataptr;

typedef int (*visit_callback)(const uint8 *n_tuples, const uint8 n,
                              const uint8 t, const uint32 index,
                              const dataptr userdata);

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/**
 * @brief lexicographic_combinations This algorithm generates all t-combinations
 * Ct...C2C1 of the n numbers {0, 1 ..., n - 1}, given n >= t >= 0. Additional
 * variables Ct+1 and Ct+2 are used as sentinels.
 * @param n the n amount of numbers
 * @param t the selected amount number
 * @param visit the visit callback function
 * @param userdata the UserData passed to visit callback function
 */
extern int lexicographic_combinations_L(const uint8 n, const uint8 t,
                                        visit_callback visit,
                                        const dataptr userdata);

/**
 * @brief lexicographic_combinations_T This algorithm likes algorithm L, but faster
 * @param n the amount of numbers
 * @param t the selected amount number
 * @param visit the visitor callback number
 * @param userdata the UserData
 */
extern int lexicographic_combinations_T(const uint8 n, const uint8 t,
                                        visit_callback visit,
                                        const dataptr userdata);

/**
 * @brief show_combination a simple callback function for print all n_tuples of
 * combinations
 * @param n_tuples the array of numbers {0, 1, ..., n - 1}
 * @param n the amount number of all
 * @param t the selected number
 * @param index the index of combination
 * @param data the userdata passed by user
 * @return
 */
extern int show_combination(const uint8 *n_tuples, const uint8 n, const uint8 t,
                            const uint32 index, const dataptr data);

/**
 * @brief copy all (n-t)_tuples of combinations to userdata
 * @param n_tuples the array of numbers {0, 1, ..., n - 1}
 * @param n the amount number of all
 * @param t the selected number
 * @param index the index of combination
 * @param data the userdata passed by user
 * @return
 */
extern int get_combination(const uint8 *n_tuples, const uint8 n, const uint8 t,
                           const uint32 index, const dataptr userdata);

/**
 * @brief get_amount_combi get the result of (n, t) combination
 * @param n the all number
 * @param t the selected number
 * @return  the result of (n, t) combination
 */
extern uint32 get_amount_combi(const uint n, const uint t);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__TAOCP_H_INCLUDE__
