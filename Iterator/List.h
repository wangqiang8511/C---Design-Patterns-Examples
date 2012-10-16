/*
*	Simple implementation of List
*
*
*	Wang Qiang @NTU 2010
*/

template <class Item>
class ListItem{
public:
	ListItem(const Item* tContent);
	~ListItem();
	Item& GetItem();
	bool Compare(Item* test);
	ListItem* next;
private:
	Item* content;
	
};

template <class Item>
class List{
public:

	List(long size = DEFAULT_LIST_CAPACITY);
	List(List&);
	~List();
	List& operator= (const List&);

	long Size() const;
	Item& Get(long index) const;
	Item& First() const;
	Item& Last() const;
	bool Includes(const Item&) const;

	void Append(const Item&);  // Push_back
	void Prepend(const Item&); // Push_front
	void Remove(const Item&);
	void RemoveLast();
	void RemoveFirst();

	Item& Top() const;
	void Push(const Item&);   // Push_back
	Item& Pop();


private:
	long capacity;
	long currentSize;
	ListItem<Item>* rootNote;
	static const long DEFAULT_LIST_CAPACITY = 100;
};


//////////////////////////////////////////////////////////////////////////
///		Class List
//////////////////////////////////////////////////////////////////////////
// Constructors


template <class Item>
List<Item>::List( long size /*= DEFAULT_LIST_CAPACITY*/ ) : 
capacity(size),
currentSize(0),
rootNote(NULL){

}

template <class Item>
List<Item>::~List(){

}

template <class Item>
List<Item>& List<Item>::operator=( const List& rhs){
	if(this == &rhs){
		return *this; 
	} else {
		(*this).capacity = rhs.capacity;
		(*this).currentSize = rhs.currentSize;
		(*this).rootNote = rhs.rootNote;
		return *this;
	}
}

template <class Item>
List<Item>::List( List& rhs){
	(*this).capacity = rhs.capacity;
	(*this).currentSize = rhs.currentSize;
	(*this).rootNote = rhs.rootNote;
}


// Basic Operations
template <class Item>
long List<Item>::Size() const{
	return currentSize;
}

template <class Item>
Item& List<Item>::Get( long index ) const{
	ListItem<Item>* p = rootNote;
	for(int i = 0; i < index - 1; i++){
		p = p->next;
	}
	return p->GetItem();
}

template <class Item>
Item& List<Item>::First() const{
	return rootNote->GetItem(); 
}

template <class Item>
Item& List<Item>::Last() const{
	return Get(currentSize);
}
template <class Item>
bool List<Item>::Includes( const Item& test) const{
	ListItem<Item>* p = rootNote;
	for(int i = 0; i < currentSize; i++){
		if(p->Compare(&test)){
			return true;
		}
		p = p->next;
	}
	return false;
}

// List Operation
template <class Item>
void List<Item>::Append( const Item& temp){
	ListItem<Item>* tempNode = new ListItem<Item>(& temp);
	if (currentSize == 0)	{
		rootNote = tempNode;
		currentSize++;
	} else {
		ListItem<Item>* p = rootNote;
		for (int i = 0 ; i < currentSize - 1; i++){
			p = p->next;
		}
		p->next = tempNode;
		currentSize++;
	}
}

template <class Item>
void List<Item>::Prepend( const Item& temp){
	ListItem<Item>* temp = new ListItem<Item>(& temp);
	if (currentSize == 0)	{
		rootNote = temp;
		currentSize++;
	} else {
		temp->next = rootNote;
		rootNote = temp;
		currentSize++;
	}
}

template <class Item>
void List<Item>::Remove( const Item& test){
	ListItem<Item>* p = rootNote;
	if(p->Compare(&test)){
		RemoveFirst();
	} else {
		for(int i = 1; i < currentSize; i++){
			ListItem<Item>* temp = p;
			p = p->next;
			if(p->Compare(&test)){
				temp->next = p->next;
				delete p;
				currentSize--;
			}
		}
	}
}

template <class Item>
void List<Item>::RemoveLast(){
	ListItem* p = rootNote;
	for(int i = 1; i < currentSize-1; i++){
		p = p->next;
	}
	ListItem* temp = p;
	p = p->next;
	delete p;
	temp->next = NULL;
	currentSize--;
}

template <class Item>
void List<Item>::RemoveFirst(){
	if (currentSize != 1){
		ListItem* p = rootNote;
		rootNote = rootNote->next;
		delete p;
		currentSize--;
	} else {
		delete rootNote;
		currentSize--;
	}
}


// Stack Operation
template <class Item>
Item& List<Item>::Pop(){
	Item* temp = &Last();
	RemoveLast();
	return *temp;
}

template <class Item>
void List<Item>::Push( const Item& temp){
	Append(temp);
}

template <class Item>
Item& List<Item>::Top() const{
	return Last();
}

//////////////////////////////////////////////////////////////////////////
///		Class ListItem
//////////////////////////////////////////////////////////////////////////
// ListItem
template <class Item>
ListItem<Item>::~ListItem(){

}
template <class Item>
ListItem<Item>::ListItem(const Item* tContent ) : content(const_cast<Item*>(tContent)) , next(NULL){

}

template <class Item>
Item& ListItem<Item>::GetItem(){
	return *content;
}

template <class Item>
bool ListItem<Item>::Compare( Item* test ){
	if(content == test){
		return true;
	} else {
		return false;
	}
}



