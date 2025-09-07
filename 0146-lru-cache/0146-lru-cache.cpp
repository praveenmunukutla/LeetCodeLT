struct node{
	int key;
	int val;
	node* next;
	node* prev;
};

struct nodefl{
	node* first;
	node* last;
};

node nodes[10000];
int nindex;

node* getNode(int key, int val){
	node* temp = &nodes[nindex++];
	temp->key = key;
	temp->val = val;
	temp->next = temp->prev = nullptr;
	return temp;
}

class LRUCache {
	int tcapacity;
	int mycapacity;
	nodefl nfl;
	unordered_map<int, node*> map;
public:
	LRUCache(int capacity) {
		tcapacity = capacity;
		mycapacity = nindex = 0;
		nfl.first = nfl.last = nullptr;
	}

	void touch(int key){
		node* temp = map[key];
		if (nfl.first == temp && nfl.last == temp){
			return;
		}
		else if (nfl.first == temp && nfl.last != temp){
			return;
		}
		else if (nfl.first != temp && nfl.last == temp){
			nfl.last = nfl.last->prev;
			nfl.last->next = nullptr;
			nfl.first->prev = temp;
			temp->next = nfl.first;
			nfl.first = temp;
			return;
		}
		else {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp->next = nfl.first;
			nfl.first->prev = temp;
			nfl.first = temp;
			return;
		}
	}

	int get(int key) {
		if (map.find(key) == map.end())
			return -1;

		touch(key);
		return map[key]->val;
	}

	void put(int key, int value) {
		if (map.find(key) != map.end()){
			touch(key);
			map[key]->val = value;
			return;
		}
		
		node* temp = getNode(key, value);
		map[key] = temp;

		if (mycapacity == tcapacity){
			if (nfl.first == nfl.last){
				map.erase(nfl.last->key);
				nfl.first = nfl.last = temp;
				return;
			}
			else{
				nfl.first->prev = temp;
				temp->next = nfl.first;
				nfl.first = temp;

				map.erase(nfl.last->key);
				nfl.last = nfl.last->prev;
				nfl.last->next = nullptr;
				return;
			}
		}
		

		mycapacity++;
		if (nfl.first == nullptr && nfl.last == nullptr){
			nfl.first = nfl.last = temp;
			return;
		}
		temp->next = nfl.first;
		nfl.first->prev = temp;
		nfl.first = temp;
	}
};