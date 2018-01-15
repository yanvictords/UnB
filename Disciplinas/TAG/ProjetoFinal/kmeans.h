#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
class Point{
private:
	int id_point, id_cluster;
	vector<double> values;
	int total_values;
	string name;

public:
	Point(int id_point, vector<double>& values, string name);
	Point(int id_point, vector<double>& values);
	int getID();
	void setCluster(int id_cluster);
	int getCluster();
	double getValue(int index);
	int getTotalValues();
	void addValue(double value);
	string getName();
};

class Cluster{
private:
	int id_cluster;
	vector<double> central_values;
	vector<Point> points;

public:
	Cluster(int id_cluster, Point point);
	void addPoint(Point point);
	bool removePoint(int id_point);
	double getCentralValue(int index);
	void setCentralValue(int index, double value);
	Point getPoint(int index);
	int getTotalPoints();
	int getID();
};

class KMeans{
private:
	int K; // number of clusters
	int total_values, total_points, max_iterations;
	vector<Cluster> clusters;
	// return ID of nearest center (uses euclidean distance)
	int getIDNearestCenter(Point point);
public:
	KMeans(int K, int total_points, int total_values, int max_iterations);
	void run(vector<Point> & points);
};
