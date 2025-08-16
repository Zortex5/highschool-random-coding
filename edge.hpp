struct Edge{
    int a, b, w;
    Edge(int start, int end, int weight):
    a(start), b(end), w(weight)
    {
    }
    bool operator<(const Edge &e)
    const { // sort by weight
        return w < e.w;
    }
};
