int max2(int a, int b) {
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}

int max3(int a, int b, int c) {
  int maxab;
  maxab = max2(a, b);
  return max2(c, maxab);
}

int max4(int a, int b, int c, int d) {
  int maxabc;
  maxabc = max3(a, b, c);
  return max2(maxabc, d);
}

int main() {
  int a, b, c, d, max;
  a = 20 * 1;
  b = 69 + 0;
  c = 1;
  d = 35;
  max = max4(a, b, c, d);
  printf(max);
}
