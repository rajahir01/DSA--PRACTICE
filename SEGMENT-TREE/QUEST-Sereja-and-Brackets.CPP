// https://codeforces.com/problemset/problem/380/C
// Sereja has a bracket sequence s1, s2, ..., sn, or, in other words, a string s of length n, consisting of characters "(" and ")".

// Sereja needs to answer m queries, each of them is described by two integers li, ri (1 ≤ li ≤ ri ≤ n). The answer to the i-th query is the length of the maximum correct bracket subsequence of sequence sli, sli + 1, ..., sri. Help Sereja answer all queries.

// You can find the definitions for a subsequence and a correct bracket sequence in the notes.

// Input
// The first line contains a sequence of characters s1, s2, ..., sn (1 ≤ n ≤ 106) without any spaces. Each character is either a "(" or a ")". The second line contains integer m (1 ≤ m ≤ 105) — the number of queries. Each of the next m lines contains a pair of integers. The i-th line contains integers li, ri (1 ≤ li ≤ ri ≤ n) — the description of the i-th query.

// Output
// Print the answer to each question on a single line. Print the answers in the order they go in the input.
  // () means one balanced bracket and length is 2.
//   Examples
// input
// ())(())(())(
// 7
// 1 1
// 2 3
// 1 2
// 1 12
// 8 12
// 5 11
// 2 10
// output
// 0
// 0
// 2
// 10
// 4
// 6
// 6


