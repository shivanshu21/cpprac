/*
 * Basic graph nodes and interface
 */

# include <iostream>
# include "graph.h"
using namespace std;

gnode::gnode()
{
    this.distance = 0;
    this.value = "";
    this.color = gnode::white;
}

gnode::gnode(string val) : value(val)
{
    this.distance = 0;
    this.color = gnode::white;
}

~gnode() {}

void gnode::setDistance(int d)
{
    this.distance = d;
}

int gnode::getDistance()
{
    return this.distance;
}

string gnode::getValue()
{
    return this.value;
}

const uint32_t gnode::getColor()
{
    return this.color;
}

vector<gnode*> gnode::getAdj()
{
    return this.adj;
}

void gnode::setAdj(vector<gnode*> a)
{
    this.adj = a;
}

void graph::addNewNode(gnode& obj, vector<string> alist)
{
    vector<gnode*> adj;
    if (getAdjByName(alist, adj)) {
        obj.setAdj(adj);
    } else {
        cout << "Failed to get adjacency list\n";
    }
    g.insert(obj.getValue(), &obj);
    return;
}

bool graph::getAdjByName(vector<string>& alist, vector<gnode*>& adj)
{
    vector<string>::iterator v;
    pair<string, gnode*> p;

    for (v = alist.begin(); v != alist.end(); v++) {
        p = g.find(*v);
        if (p.first != g.end()) {
            adj.push_back(p.second);
        }
    }
    return true;
}

int main()
{
    graph nodes = new graph();
    gnode obj1 = new gnode("A");
    gnode obj2 = new gnode("B");
    gnode obj3 = new gnode("B");
    gnode obj4 = new gnode("D");

    vector<string> an {"B", "C"};
    nodes.addNewNode(obj1, an);
    vector<string> bn {"C", "A"};
    nodes.addNewNode(obj2, bn);
    vector<string> cn {"B", "A", "D"};
    nodes.addNewNode(obj3, cn);
    vector<string> dn {"C"};
    nodes.addNewNode(obj4, dn);

    nodes.addNewNode(obj1, an);
    nodes.addNewNode(obj2, bn);
    nodes.addNewNode(obj3, cn);
    nodes.addNewNode(obj4, dn);
    return 0;
}
