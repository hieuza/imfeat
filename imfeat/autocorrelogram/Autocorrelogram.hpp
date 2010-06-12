#ifndef AUTOCORRELOGRAM_H
#define AUTOCORRELOGRAM_H
#include <vector>

std::vector<int> convert_colors_rg16(char *data_signed, int size);
std::vector<int> convert_colors_rg64(char *data_signed, int size);
class Autocorrelogram {
public:
  Autocorrelogram(int height, int width, int unique_colors, std::vector<int> distance_set);
  ~Autocorrelogram();
  /* The data is input as a char*, the values are binned.  The maximum value is colors - 1 */
  std::vector<double> compute(const unsigned char *char_data);
  std::vector<double> compute(const char *char_data);
private:
  void clear();
  void update_lambda_x(const unsigned char *data, int k, unsigned char color);
  void update_lambda_y(const unsigned char *data, int k, unsigned char color);
  bool is_dist_in_set(int k);
  void build_hist(const unsigned char *data);
  void build_hist(const char *data);
  double make_correlogram_scalar(const unsigned char *data, int k, unsigned char color);
  const int height;
  const int width;
  const int unique_colors;
  const std::vector<int> distance_set;
  const int max_dist;
  const int max_height;
  const int max_width;
  unsigned int *lambda_x;
  unsigned int *lambda_y;
  unsigned int *hist;
};
#endif
