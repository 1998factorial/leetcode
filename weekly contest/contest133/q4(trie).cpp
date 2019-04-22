//trie version 1
const int SIGMA = 26;
struct Node {
  Node* child[SIGMA];
  Node* fail;
  bool visit;
};

const int N = 4e6 + 10;
Node pool[N], *last;

Node* new_node(Node* fail) {
  Node* p = last++;
  p->fail = fail;
  fill(p->child, p->child + SIGMA, (Node*)nullptr);
  p->visit = false;
  return p;
}

void insert(const string& s, Node* root) {
  Node* p = root;
  for (int i = 0; i < s.size(); ++i) {
    int k = s[i] - 'a';
    if (!p->child[k]) {
      p->child[k] = new_node(root);
    }
    p = p->child[k];
  }
  p->visit = true;
}

void build_ac_automaton(Node* root) {
  queue<Node*> Q;
  for (int k = 0; k < SIGMA; ++k) {
    if (root->child[k]) {
      Q.push(root->child[k]);
    }
  }
  while (!Q.empty()) {
    Node* p = Q.front();
    Q.pop();
    for (int k = 0; k < SIGMA; ++k) {
      if (!p->child[k]) {
        p->child[k] = p->fail->child[k];
      } else {
        p->child[k]->fail = p->fail->child[k] ? p->fail->child[k] : root;
        Q.push(p->child[k]);
      }
    }
    p->visit |= p->fail->visit;
  }
}

class StreamChecker {
public:
    Node* root;
    Node* p;
    StreamChecker(vector<string>& words) {
        last = pool;
        root = new_node(nullptr);
        for (auto& s : words) {
            insert(s, root);
        }
        build_ac_automaton(root);
        p = root;
    }
    
    bool query(char c) {
        int k = c - 'a';
        p = p->child[k] ? p->child[k] : root;
        return p->visit;        
    }
};
//trie version 2
struct trieNode{
	int child[26];
	bool end;
}nodes[40005];

class StreamChecker {
public:
	int cnt,nq;
	int q[40005];
	int newnode(){
		int ret=cnt++;
		memset(&nodes[ret],0,sizeof(trieNode));
		return ret;
	}

    StreamChecker(vector<string>& words) {
    	cnt=1;
    	memset(&nodes[0],0,sizeof(trieNode));
    	for(const string& w : words){
    		int m=w.size(),p=0;
    		for(int i=m-1;i>=0;i--){
    			if(!nodes[p].child[w[i]-'a'])
    				nodes[p].child[w[i]-'a']=newnode();
    			p=nodes[p].child[w[i]-'a'];	
    		}
    		nodes[p].end=true;
    	}
    	nq=0;
    }
    
    bool query(char c) {
    	q[nq++]=c-'a';
    	int p=0;
    	for(int i=nq-1;i>=0;i--){
    		if(!nodes[p].child[q[i]])return false;
    		p=nodes[p].child[q[i]];
    		if(nodes[p].end)return true;
    	}
    	return false;
    }
};




