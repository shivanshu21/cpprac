/*
 * Basic graph nodes and interface
 */
# ifndef __BASIC_GRAPH_H__
# define __BASIC_GRAPH_H__
# include <string>
# include <vector>
# include <map>

class gnode {
    private:
        int distance;
        string value;
        enum gcolor {
            white = 0,
            grey  = 1,
            black = 2
        };
        gcolor color;
        vector<gnode*> adj;
        vector<gnode*> parents;

    public:
        gnode();
        gnode(string);
        ~gnode();
        void setDistance(int);
        int getDistance();
        string getValue();
        const uint32_t getColor();
        vector<gnode*> getAdj();
        void setAdj(vector<gnode*> a);
};

class graph {
    public:
    map<string, gnode*> g;
    void addNewNode(string val, vector<string> alist);
    bool getAdjByName(vector<string>&, vector<gnode*>&);
};

# endif
