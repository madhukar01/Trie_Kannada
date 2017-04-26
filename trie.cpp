#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include <array>

using namespace std;

#define ALPHABETS 528
#define MAX_WORD_SIZE 50

class uniascii
{
    private:
        map<string, int> unimap;
        vector<string> chararr;
        vector<int> indexarr;
        vector<string> alphabets = {
            "C","D","E","F","G","H","IÄ","J","K","L","M","N","O","CA","CB",
            
            "Pï","PÀ","PÀÌ","PÁ","Q","QÃ","PÀÄ","PÀÆ","PÀÈ","PÉ","PÉÃ","PÉÊ","PÉÆ","PÉÆÃ","PË","PÀA","PÀB",
            "Sï","R","SÁ","T","TÃ","RÄ","RÆ","RÈ","SÉ","SÉÃ","SÉÊ","SÉÆ","SÉÆÃ","SË","RA","RB",
            "Uï","UÀ","UÁ","V","VÃ","UÀÄ","UÀÆ","UÀÈ","UÉ","UÉÃ","UÉÊ","UÉÆ","UÉÆÃ","UË","UÀA","UÀB",
            "Wï","WÀ","WÁ","X","XÃ","WÀÄ","WÀÆ","WÀÈ","WÉ","WÉÃ","WÉÊ","WÉÆ","WÉÆÃ","WË","WÀA","WÀB",
            
            "Zï","ZÀ","ZÁ","a","aÃ","ZÀÄ","ZÀÆ","ZÀÈ","ZÉ","ZÉÃ","ZÉÊ","ZÉÆ","ZÉÆÃ","ZË","ZÀA","ZÀB",
            "bï","bÀ","bÁ","c","cÃ","bÀÄ","bÀÆ","bÀÈ","bÉ","bÉÃ","bÉÊ","bÉÆ","bÉÆÃ","bË","bÀA","bÀB",
            "eï","d","eÁ","f","fÃ","dÄ","dÆ","dÈ","eÉ","eÉÃ","eÉÊ","eÉÆ","eÉÆÃ","eË","dA","dB",
            "gÀhiï","gÀhÄ","gÀhiÁ","jhÄ","jhÄÃ","gÀhÄÄ","gÀhÄÆ","gÀhÄÈ","gÉhÄ","gÉhÄÃ","gÉhÄÊ","gÉhÆ","gÉhÆÃ","gÀhiË","gÀhÄA","gÀhÄB",
            
            "mï","l","mÁ","n","nÃ","lÄ","lÆ","lÈ","mÉ","mÉÃ","mÉÊ","mÉÆ","mÉÆÃ","mË","lA","lB",
            "oï","oÀ","oÁ","p","pÃ","oÀÄ","oÀÆ","oÀÈ","oÉ","oÉÃ","oÉÊ","oÉÆ","oÉÆÃ","oË","oÀA","oÀB",
            "qï","qÀ","qÁ","r","rÃ","qÀÄ","qÀÆ","qÀÈ","qÉ","qÉÃ","qÉÊ","qÉÆ","qÉÆÃ","qË","qÀA","qÀB",
            "qsï","qsÀ","qsÁ","rü","rüÃ","qsÀÄ","qsÀÆ","qsÀÈ","qsÉ","qsÉÃ","qsÉÊ","qsÉÆ","qsÉÆÃ","qsË","qsÀA","qsÀB",
            "uï","t","uÁ","tÂ","tÂÃ","tÄ","tÆ","tÈ","uÉ","uÉÃ","uÉÊ","uÉÆ","uÉÆÃ","uË","tA","tB",
            
            "vï","vÀ","vÁ","w","wÃ","vÀÄ","vÀÆ","vÀÈ","vÉ","vÉÃ","vÉÊ","vÉÆ","vÉÆÃ","vË","vÀA","vÀB",
            "xï","xÀ","xÁ","y","yÃ","xÀÄ","xÀÆ","xÀÈ","xÉ","xÉÃ","xÉÊ","xÉÆ","xÉÆÃ","xË","xÀA","xÀB",
            "zï","zÀ","zÁ","¢","¢Ã","zÀÄ","zÀÆ","zÀÈ","zÉ","zÉÃ","zÉÊ","zÉÆ","zÉÆÃ","zË","zÀA","zÀB",
            "zsï","zsÀ","zsÁ","¢ü","¢üÃ","zsÀÄ","zsÀÆ","zsÀÈ","zsÉ","zsÉÃ","zsÉÊ","zsÉÆ","zsÉÆÃ","zsË","zsÀA","zsÀB",
            "£ï","£À","£Á","¤","¤Ã","£ÀÄ","£ÀÆ","£ÀÈ","£É","£ÉÃ","£ÉÊ","£ÉÆ","£ÉÆÃ","£Ë","£ÀA","£ÀB",
            
            "¥ï","¥À","¥Á","¦","¦Ã","¥ÀÄ","¥ÀÆ","¥ÀÈ","¥É","¥ÉÃ","¥ÉÊ","¥ÉÆ","¥ÉÆÃ","¥Ë","¥ÀA","¥ÀB",
            "¥sï","¥sÀ","¥sÁ","¦ü","¦üÃ","¥sÀÄ","¥sÀÆ","¥sÀÈ","¥sÉ","¥sÉÃ","¥sÉÊ","¥sÉÆ","¥sÉÆÃ","¥sË","¥sÀA","¥sÀB",
            "¨ï","§","¨Á","©","©Ã","§Ä","§Æ","§È","¨É","¨ÉÃ","¨ÉÊ","¨ÉÆ","¨ÉÆÃ","¨Ë","§A","§B",
            "¨sï","¨sÀ","¨sÁ","©ü","©üÃ","¨sÀÄ","¨sÀÆ","¨sÀÈ","¨sÉ","¨sÉÃ","¨ÉÊ","¨sÉÆ","¨sÉÆÃ","¨sË","¨sÀA","¨sÀB",
            "ªÀiï","ªÀÄ","ªÀiÁ","«Ä","«ÄÃ","ªÀÄÄ","ªÀÄÆ","ªÀÄÈ","ªÉÄ","ªÉÄÃ","ªÉÄÊ","ªÉÆ","ªÉÆÃ","ªÀiË","ªÀÄA","ªÀÄB",
            
            "AiÀiï","AiÀÄ","AiÀiÁ","¬Ä","¬ÄÃ","AiÀÄÄ","AiÀÄÆ","AiÀÄÈ","AiÉÄ","AiÉÄÃ","AiÉÄÊ","AiÉÆ","AiÉÆÃ","AiÀiË","AiÀÄA","AiÀÄB",
            "gï","gÀ","gÁ","j","jÃ","gÀÄ","gÀÆ","gÀÈ","gÉ","gÉÃ","gÉÊ","gÉÆ","gÉÆÃ","gË","gÀA","gÀB",
            "¯ï","®","¯Á","°","°Ã","®Ä","®Æ","®È","¯É","¯ÉÃ","¯ÉÊ","¯ÉÆ","¯ÉÆÃ","¯Ë","®A","®B",
            "ªï","ªÀ","ªÁ","«","«Ã","ªÀÅ","ªÀÇ","ªÀÈ","ªÉ","ªÉÃ","ªÉÊ","ªÉÇ","ªÉÇÃ","ªË","ªÀA","ªÀB",
            "±ï","±À","±Á","²","²Ã","±ÀÄ","±ÀÆ","±ÀÈ","±É","±ÉÃ","±ÉÊ","±ÉÆ","±ÉÆÃ","±Ë","±ÀA","±ÀB",
            "µï","µÀ","µÁ","¶","¶Ã","µÀÄ","µÀÆ","µÀÈ","µÉ","µÉÃ","µÉÊ","µÉÆ","µÉÆÃ","µË","µÀA","µÀB",
            "¸ï","¸À","¸Á","¹","¹Ã","¸ÀÄ","¸ÀÆ","¸ÀÈ","¸É","¸ÉÃ","¸ÉÊ","¸ÉÆ","¸ÉÆÃ","¸Ë","¸ÀA","¸ÀB",
            "ºï","ºÀ","ºÁ","»","»Ã","ºÀÄ","ºÀÆ","ºÀÈ","ºÉ","ºÉÃ","ºÉÊ","ºÉÆ","ºÉÆÃ","ºË","ºÀA","ºÀB",
            "¼ï","¼À","¼Á","½","½Ã","¼ÀÄ","¼ÀÆ","¼ÀÈ","¼É","¼ÉÃ","¼ÉÊ","¼ÉÆ","¼ÉÆÃ","¼Ë","¼ÀA","¼ÀB"
            };

    public:
        uniascii();
        void convert(string word);
        vector<string> getchararr(string s);
        vector<int> getindexarr(string s);
        int getascii(string s);
        string getchar(int x);
        void display();
};

uniascii::uniascii()
{
    int count = 0;
    for(auto it = alphabets.begin(); it != alphabets.end(); ++it)
    {
        unimap[*it] = count;
        count++;
    }
}

int uniascii::getascii(string s)
{
    auto it = unimap.find(s);
    return it->second;
}

string uniascii::getchar(int x)
{
    for(auto it = unimap.begin(); it!=unimap.end(); it++)
    {    
        if(it->second == x)
            return it->first;
    }
    return NULL;
}

vector<string> uniascii::getchararr(string s)
{
    convert(s);
    return chararr;
}

vector<int> uniascii::getindexarr(string s)
{
    convert(s);
    return indexarr;
}

void uniascii::convert(string s)
{
    //cout<<"Size: "<<unimap.size()<<endl;
    int start = 0, len = s.length(), chars=1;
    chararr.clear();
    indexarr.clear();
    while((start+chars)<=len)
    {
        int temp = 0, temp1 = 0;
        string currword = "";
        bool found = false;
        string current = s.substr(start, chars);
        //cout << "Lookahead 1: " << current << endl;
        auto it = unimap.find(current);
        if(it != unimap.end())
        {
            currword = it->first;
            temp1 = it->second;
            temp = start+1;
            found = true;
            //cout<<"Found: "<<current<<endl;
        }
        chars++;
        if(start+chars <= len)
        {
            current = s.substr(start, chars);
            //cout << "Lookahead 2: " << current << endl;
            it = unimap.find(current);
            if(it != unimap.end())
            {
                currword = it->first;
                temp1 = it->second;
                temp = start+2;
                found = true;
                //cout<<"Found: "<<current<<endl;
            }
        }
        chars++;
        if(start+chars <= len)
        {
            current = s.substr(start, chars);
            //cout << "Lookahead 3: " << current << endl;
            it = unimap.find(current);
            if(it != unimap.end())
            {
                currword = it->first;
                temp1 = it->second;
                temp = start+3;
                found = true;
                //cout<<"Found: "<<current<<endl;
            }
        }
        chars++;
        if(start+chars <= len)
        {
            current = s.substr(start, chars);
            //cout << "Lookahead 4: " << current << endl;
            it = unimap.find(current);
            if(it != unimap.end())
            {
                currword = it->first;
                temp1 = it->second;
                temp = start+4;
                found = true;
                //cout<<"Found: "<<current<<endl;
            }
        }
        chars++;
        if(start+chars <= len)
        {
            current = s.substr(start, chars);
            //cout << "Lookahead 5: " << current << endl;
            it = unimap.find(current);
            if(it != unimap.end())
            {
                currword = it->first;
                temp1 = it->second;
                temp = start+5;
                found = true;
                //cout<<"Found: "<<current<<endl;
            }
        }
        chars++;
        if(start+chars <= len)
        {
            current = s.substr(start, chars);
            //cout << "Lookahead 6: " << current << endl;
            it = unimap.find(current);
            if(it != unimap.end())
            {
                currword = it->first;
                temp1 = it->second;
                temp = start+6;
                found = true;
                //cout<<"Found: "<<current<<endl;
            }
        }
        chars++;
        if(start+chars <= len)
        {
            current = s.substr(start, chars);
            //cout << "Lookahead 7: " << current << endl;
            it = unimap.find(current);
            if(it != unimap.end())
            {
                currword = it->first;
                temp1 = it->second;
                temp = start+7;
                found = true;
                //cout<<"Found: "<<current<<endl;
            }
        }
        chars++;
        if(start+chars <= len)
        {
            current = s.substr(start, chars);
            //cout << "Lookahead 8: " << current << endl;
            it = unimap.find(current);
            if(it != unimap.end())
            {
                currword = it->first;
                temp1 = it->second;
                temp = start+8;
                found = true;
                //cout<<"Found: "<<current<<endl;
            }
        }
        if(!found)
        {
            cout<<"Invalid word: "<< s<<endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            //cout<<"Found Character: "<<currword << endl;
            chars=1;
            start = temp;
            chararr.push_back(currword);
            //cout<<"Pushing: "<<currword;
            indexarr.push_back(temp1);
        }
    }
}

void uniascii::display()
{
    for(auto it = unimap.begin(); it != unimap.end(); ++it)
    {
        cout << it->first << " => " <<it->second << endl;
    }
    cout << "Total alphabets: " << unimap.size() << endl;
}

class Node
{
    public:
        Node * parent;
        array<Node *, ALPHABETS> children;
        int childnodes;
        bool leaf;
        vector<int> occurrences;
        Node()
        {
            childnodes = 0;
            leaf = false;
        }
};

class TrieTree
{
    private:
        Node * root;
        int count;
        uniascii converter;
        vector<string> lexwords;
    
    public:
        TrieTree();
        void insert(string input);
        void triesort(Node * trie_tree, vector<string>& util);
        bool find(string input);
        void remove(string input);
        vector<string>::iterator begin();
        vector<string>::iterator end();
        void display();
};

TrieTree::TrieTree()
{
    root = (Node *) calloc(1, sizeof(Node));
    count = 0;
};

void TrieTree::insert(string input)
{
    vector<string> word = converter.getchararr(input);

    Node * temp = root;
    int i = 0, index = 0;

    while(i < word.size())
    {
        index = converter.getascii(word[i]);
        if(temp->children[index] == NULL)
        {
            temp->children[index] = (Node *) calloc(1, sizeof(Node));
            temp->children[index]->parent = temp;
        }
        temp = temp->children[index];
        temp->childnodes++;
        ++i;
    }
    count++;
    temp->occurrences.push_back(count);
    temp->leaf = true;
}

void TrieTree::triesort(Node * trie_tree, vector<string>& util)
{
    int i=0;
    for(auto it: trie_tree->children)
    {
        if (it == NULL)
        {
            ++i;
            continue;
        }
        else
        {
            util.push_back(converter.getchar(i));
            triesort(it, util);
            ++i;
        }
    }
    if(trie_tree->leaf)
    {
        string s = "";
        //cout << "Printing word: "<<endl;
        for(auto it:util)
            s+=it;
            //cout << it <<" ";
        //cout <<s<< " @ index ";
        lexwords.push_back(s);
        /*for(auto it:trie_tree->occurrences)
            cout << it << " ";
        cout << endl;*/
    }
    if(util.size()>0)
        util.pop_back();
}

vector<string>::iterator TrieTree::begin()
{
    vector<string> v;
    lexwords.clear();
    triesort(root, v);
    return lexwords.begin();
}

vector<string>::iterator TrieTree::end()
{
    vector<string> v;
    lexwords.clear();
    triesort(root, v);
    return lexwords.end();
}

bool TrieTree::find(string input)
{
    for(auto it = begin(); it != end(); ++it)
    {
        if(input.compare(*it) == 0)
        {
            cout << "Word " << input << " found" <<endl;
            return true;
        }
    }
    cout << "Word " << input << " not found " <<endl;
    return false;
}

void TrieTree::remove(string input)
{
    if(find(input)){
        vector<string> word = converter.getchararr(input);
        Node *temp = root;
        int i = 0, index = 0;

        while(i<word.size())
        {
            index = converter.getascii(word[i]);
            //cout<<"char "<<converter.getchar(index)<<"\t";
            temp = temp->children[index];
            ++i;
        }
        if(temp->leaf) temp->occurrences.pop_back();
        if(temp->childnodes != 0)
        {
            //cout<<"here "<<temp->parent->childnodes<<endl;
            temp->leaf = false;
            temp->parent->childnodes--;
            return;
        }

        Node * traverse = temp->parent;

        while(traverse != NULL)
        {
            int i = 0;
            for(auto it:traverse->children)
            {
                if(it == temp)
                    {
                        //cout<<"Child "<<traverse->childnodes<<endl;
                        traverse->children[i] = NULL;
                        traverse->childnodes--;
                        break;
                    }
                i++;
            }

            if(traverse->childnodes>1)return;
            if(traverse == root) return;
            if(traverse->childnodes == 0) traverse = traverse->parent;
        }
    }
    else
        return;
}

void TrieTree::display()
{
    cout << "Printing" << endl;
    for(auto it = begin(); it!=end(); ++it)
        cout << *it <<endl;
}

int main()
{
    int option = 0;
    TrieTree mytree;
    //mytree.converter.display();
    string word;
    cout << "Welcome to ಕನ್ನ ಡ ಮ ರ"<<endl;
    while(option != 5)
    {
        cout << "\nEnter Option\n1.Insert\n2.Find\n3.Remove\n4.Display\n5.Exit\nOption: ";
        cin >> option;
        cout << endl;
        switch(option)
        {
            case 1: {
                        cout << "Enter Word to Insert: " << endl;
                        cin >> word;
                        mytree.insert(word);
                    }break;
            case 2: {
                        cout << "Enter Word to Find: " << endl;
                        cin >> word;
                        mytree.find(word);
                    }break;
            case 3: {
                        cout << "Enter Word: " << endl;
                        cin >> word;
                        mytree.remove(word);
                    }break;
            case 4: { mytree.display();}break;
            case 5: break;
            default: {option =5;}break;
        }
    }

}