#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// first: start of a line segment, second: end of a line segment.
using Line = pair<int, int>;

bool is_intersect(Line &left, Line &right) {
  return (right.first <= left.second);
}

void extend_line(Line &left, Line &right) {
  left.second = max(left.second, right.second);
}

int lines_coverage(vector<Line> &lines) {
  if (lines.empty()) return 0;

  sort(lines.begin(), lines.end());

  int length = 0;
  Line left = lines[0];
  for (auto &right : lines) {
    if (is_intersect(left, right)) {
      extend_line(left, right);
    } else {
      length += (left.second - left.first);
      left = right;
    }
  }
  length += (left.second - left.first);
  return length;
}

struct Point {
  int x;
  int y;
};

struct Rect {
  Point upper_left;
  Point lower_right;
};

struct Cut {
  int x;         // x-axis of upper_left or lower_right of a rectangle.
  bool leaving;  // leaving a rectangle.
  Line line;     // vertical line of a rectangle.
  friend ostream &operator<<(ostream &os, Cut &cut);
};

ostream &operator<<(ostream &os, Cut &cut) {
  os << "x = " << cut.x << " ";
  os << "leaving = " << cut.leaving << " ";
  os << "line = (" << cut.line.first << ", " << cut.line.second << ") ";
  return os;
}

int rects_coverage(vector<Rect> &rects) {
  if (rects.empty()) return 0;

  auto cut_greater = [](const Cut& c1, const Cut& c2) {
    if (c1.x > c2.x)
      return true;
     else if (c1.x == c2.x)
       return !c1.leaving;
    else
      return false;
  };

  // Set up a priority_queue to scan rectangles from left to right, leaving to
  // entering.
  priority_queue<Cut, vector<Cut>, decltype(cut_greater)> cuts(cut_greater);
  for (const auto &rect : rects) {
    cuts.push(
        {rect.upper_left.x, false, {rect.upper_left.y, rect.lower_right.y}});
    cuts.push(
        {rect.lower_right.x, true, {rect.upper_left.y, rect.lower_right.y}});
  }

  // For each cut, if its x-axis is changed, update area and restart one.
  // if the cut is right side of a rectangle, remove the line from active line
  // segments. if the cut is left side of a rectangle, add the line to active
  // line segments.
  vector<Line> active_lines;
  int prev_x = cuts.top().x;
  int area = 0;
  while (!cuts.empty()) {
    Cut cut = cuts.top();
    cuts.pop();
    // cout << cut << endl;

    if (cut.x != prev_x) {
      area += (cut.x - prev_x) * lines_coverage(active_lines);
      prev_x = cut.x;
    }
    if (cut.leaving) {
      auto it = find(active_lines.begin(), active_lines.end(), cut.line);
      if (it != active_lines.end()) active_lines.erase(it);
    } else {
      active_lines.push_back(cut.line);
    }
  }
  return area;
}

int main() {
  vector<Line> lines = {{1, 3}, {2, 4}, {5, 6}, {7, 10}, {8, 9}};
  cout << "lines coverage: " << lines_coverage(lines) << endl;

  vector<Rect> rects = {{{1, 1}, {3, 3}}, {{2, 2}, {3, 3}}, {{3, 3}, {4, 4}},
                        {{3, 5}, {4, 6}}, {{5, 5}, {7, 7}}, {{6, 6}, {8, 8}}};
  cout << "rects coverage: " << rects_coverage(rects) << endl;
  return 0;
}
