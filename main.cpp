#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <set>

using namespace std;

//1) Graph by adjacent lists, Undirected graph (double way)
//lists here can be arrays or linked lists

class GraphAdjLists
{
private:
    int vertexNo;
    map<char, vector<char>>myGraph;
    //map<char, list<char>>myGraph;
public:
    GraphAdjLists():vertexNo(0)
    {
    }

    void addVertex(char v)
    {
        //myGraph[v].push_back('n');
        myGraph[v] = {};
    }

    void addEdge(char v1, char v2)
    {
        /*
        if(*(myGraph[v1].begin()) == 'n')
        {
            myGraph[v1].remove('n');
        }
        */
        myGraph[v1].push_back(v2);
        myGraph[v2].push_back(v1);
    }

    void showConnection()
    {
        for(auto i = myGraph.begin(); i != myGraph.end(); i++)
        {
            cout << i->first << "-->";
            for(auto j = myGraph[i->first].begin(); j != myGraph[i->first].end(); j++)
            {
                cout << *j << " ";
            }
            cout << endl;
        }
    }
};
//========================================================//

//2) Graph by adjacent matrix

class GraphMatrix
{
private:
    int vertexNo;
    int myGraph[5][5];
public:
    GraphMatrix():vertexNo(5)
    {
    }

    void addEdge(int v1, int v2)
    {
        myGraph[v1][v2] = 1;
        myGraph[v2][v1] = 1;
    }

    void showConnection()
    {
        for(int i = 0; i < vertexNo; i++)
        {
            cout << "{";
            for(int j = 0; j < vertexNo; j++)
            {
                cout << myGraph[i][j] << ", ";
            }
            cout << "}" << endl;

        }
    }

};

//============================================================//

//3) Graph by edge list

class GraphEdgeList
{
private:
    int vertexNo;
    vector<vector<int>> myGraph;
public:
    GraphEdgeList():vertexNo(0)
    {
    }

    void addEdge(int v1, int v2)
    {
        myGraph.push_back({v1, v2});
    }

    void showConnection()
    {
        for(size_t i = 0; i < myGraph.size(); i++)
        {
            cout << "[";
            for(size_t j = 0; j < myGraph[i].size(); j++)
            {
                cout << myGraph[i][j] << ", ";
            }
            cout << "]" << endl;
        }
    }
};

//============================================================//

// Weighted Graph represented by adjacent lists

class WeightedGraph
{
private:
    int vertex;
    int edge;
    map<string, list<pair<string, int>>> myGraph;

public:
    WeightedGraph():vertex(0), edge(0)
    {
    }

    void addVertex(string s)
    {
        myGraph[s].push_back(make_pair("n", 0));
        vertex++;
    }

    void addEdge(string s1, string s2, int w)
    {
        auto i = myGraph[s1].begin();
        if(i->first == "n" && i->second == 0)
            myGraph[s1].remove(make_pair("n", 0));

        auto j = myGraph[s2].begin();
        if(j->first == "n" && j->second == 0)
            myGraph[s2].remove(make_pair("n", 0));

        myGraph[s1].push_back(make_pair(s2, w));
        myGraph[s2].push_back(make_pair(s1, w));
        edge++;
    }

    void display()
    {
        for(auto i = myGraph.begin(); i != myGraph.end(); i++)
        {
            cout << i->first << "-->";
            for(auto j = myGraph[i->first].begin(); j!= myGraph[i->first].end(); j++)
            {
                cout << j->first << "," << j->second << "   ";
            }
            cout << endl;
        }
    }

    void displayOne(string s)
    {
        cout << s << "-->";
        for(auto i = myGraph[s].begin(); i != myGraph[s].end(); i++)
        {
            cout << i->first << " = " << i->second << "  ";
        }
    }

};
//===========================================================================//




int main()
{
    GraphAdjLists myg;
    myg.addVertex('A');
    myg.addVertex('B');
    myg.addVertex('C');
    myg.addVertex('D');
    myg.addVertex('E');
    myg.addVertex('F');
    myg.addVertex('G');

    myg.addEdge('A', 'B');
    myg.addEdge('A', 'C');
    myg.addEdge('B', 'D');
    myg.addEdge('D', 'F');
    myg.addEdge('C', 'D');
    myg.addEdge('C', 'E');
    myg.addEdge('E', 'F');
    myg.addEdge('E', 'G');

    myg.showConnection();
    cout << "\n";
    //----------------------------//

    GraphMatrix myMat;

    myMat.addEdge(0, 1);
    myMat.addEdge(0, 2);
    myMat.addEdge(1, 2);
    myMat.addEdge(1, 3);
    myMat.addEdge(3, 4);
    myMat.addEdge(4, 2);

    myMat.showConnection();
    cout << "\n";
    //---------------------------------//

    GraphEdgeList myEdList;
    myEdList.addEdge(0, 1);
    myEdList.addEdge(0, 2);
    myEdList.addEdge(1, 3);
    myEdList.addEdge(3, 4);
    myEdList.addEdge(4, 2);
    myEdList.addEdge(1, 2);

    myEdList.showConnection();
    cout << "\n";
    //-----------------------------------//

    WeightedGraph myWg;
    myWg.addVertex("tima");
    myWg.addVertex("tahta");
    myWg.addVertex("maragha");
    myWg.addVertex("waseet");

    myWg.addEdge("tima", "tahta", 20);
    myWg.addEdge("tima", "waseet", 10);
    myWg.addEdge("waseet", "maragha", 10);
    myWg.addEdge("maragha", "tahta", 15);

    myWg.display();
    cout << endl;

    myWg.displayOne("tima");
    cout << "\n";
    //------------------------------------------//

    return 0;
}
