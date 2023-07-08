#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
  bool operator == (Segment s2){
	  return (start == s2.start && end == s2.end);
  }
  bool operator <= (Segment s2){
	  return (start <= s2.start);
  }
};

void shiftSeg(vector<Segment> &segments, int index){
	for(size_t  i = index; i < segments.size()-1; i++){
		segments[i].start = segments[i+1].start;
		segments[i].end = segments[i+1].end;
	}
}
//	My Design
vector<int> optimal_points(vector<Segment> &segments){
	vector<int> points;
	int m = 0;
	int p = 0;
	int start = segments[0].start;
	int end = segments[0].end;

	for(size_t  i = 1; i < segments.size(); i++){
		if(segments[i].start < start)
			start = segments[i].start;
		if(segments[i].end > end)
			end = segments[i].end;
	}


	while(segments.size()){
		vector<Segment> intersected(segments.size());
		int maxIntersected = 0;
		for(int i = start; i <= end; i++){
			vector<Segment> counted(segments.size());
			int count = 0;

			for(size_t  j = 0; j < segments.size(); j++)
				if(segments[j].start <= i && segments[j].end >= i)
					counted[count++] = segments[j];

			if(count > maxIntersected || i == start){
				maxIntersected = count;
				intersected = counted;
				p = i;
			}
		}
		points.push_back(p);
		for(int i = 0; i < maxIntersected; i++){
			for(size_t  j = 0; j < segments.size(); j++){
				if(segments[j] == intersected[i]){
					shiftSeg(segments, j);
					segments.pop_back();
				}
			}
		}
		intersected.clear();
	}

	return points;
}

vector<int> optimal_points_2(vector<Segment> &segments){
	
	// sorting the vector based on their end points
	sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) -> bool {
        return a.end < b.end;
    });

	vector<int> points;
	int point = segments[0].end;	// set the point to the first end point i-e shortest end point
	points.push_back(point);

	for(size_t i = 1; i < segments.size(); i++){
		if(segments[i].start > point || segments[i].end < point){		// if the point is not in the segment
            point = segments[i].end;								// update the point to the end point of the current segment
            points.push_back(point);							// store it in the vector
		}
	}

	return points;
}


int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points_2(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  system("pause");
  return 0;
}
