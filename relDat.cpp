#include <bits/stdc++.h>
// #include <string>
using namespace std;

class Attr;
class Record;
class Relation;
struct DNFformula
{
    list<list<tuple<string, char, Attr *>>> ops;
};
// all base classes declared

class Attr
{ // Base class for attributes

private:
    string type;
    // Add operators for different attribute type in derived classes
public:
    // parameterised constructor
    Attr(string type)
    {
        this->type = type;
    }

    // copy--- will be used for deep copy
    virtual Attr *copy(void) = 0;
    virtual void print()=0;
    // operators
    virtual bool operator==(const Attr &right) = 0;
    virtual bool operator!=(const Attr &right) = 0;
    virtual bool operator>(const Attr &right) = 0;
    virtual bool operator>=(const Attr &right) = 0;
    virtual bool operator<(const Attr &right) = 0;
    virtual bool operator<=(const Attr &right) = 0;
};

// Integer Attributes
class IntegerAttr : public Attr
{

protected:
    int valInt;

    IntegerAttr &operator=(const IntegerAttr &right)
    {

        if (this != &right)
        {
            this->valInt = right.valInt;
        }

        return *this;
    }

public:
    IntegerAttr(int val) : valInt(val), Attr("integer") {}
    void print(){
        printf("%15d|",this->valInt);
    }
    Attr *copy(void)
    {

        IntegerAttr *retval = dynamic_cast<IntegerAttr *>(this);

        return retval;
    }

    bool operator==(const Attr &right)
    {
        if (this->valInt == dynamic_cast<const IntegerAttr &>(right).valInt)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(const Attr &right)
    {
        if (this->valInt != dynamic_cast<const IntegerAttr &>(right).valInt)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(const Attr &right)
    {
        if (this->valInt > dynamic_cast<const IntegerAttr &>(right).valInt)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>=(const Attr &right)
    {
        if (this->valInt >= dynamic_cast<const IntegerAttr &>(right).valInt)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<(const Attr &right)
    {
        if (this->valInt < dynamic_cast<const IntegerAttr &>(right).valInt)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<=(const Attr &right)
    {
        if (this->valInt <= dynamic_cast<const IntegerAttr &>(right).valInt)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// String Attribute
class StringAttr : public Attr
{

protected:
    string valString;

    StringAttr &operator=(const StringAttr &right)
    {

        if (this != &right)
        {
            this->valString = right.valString;
        }

        return *this;
    }

public:
    StringAttr(string val) : valString(val), Attr("string") {}

    Attr *copy(void)
    {

        StringAttr *retval = dynamic_cast<StringAttr *>(this);

        return retval;
    }
    void print(){
        printf("%15s|",this->valString);
    }
    bool operator==(const Attr &right)
    {
        if (this->valString == dynamic_cast<const StringAttr &>(right).valString)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(const Attr &right)
    {
        if (this->valString != dynamic_cast<const StringAttr &>(right).valString)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(const Attr &right)
    {
        if (this->valString > dynamic_cast<const StringAttr &>(right).valString)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>=(const Attr &right)
    {
        if (this->valString >= dynamic_cast<const StringAttr &>(right).valString)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<(const Attr &right)
    {
        if (this->valString < dynamic_cast<const StringAttr &>(right).valString)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<=(const Attr &right)
    {
        if (this->valString <= dynamic_cast<const StringAttr &>(right).valString)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Float Attribute
class FloatAttr : public Attr
{

protected:
    float valFloat;
    FloatAttr &operator=(const FloatAttr &right)
    {

        if (this != &right)
        {
            this->valFloat = right.valFloat;
        }

        return *this;
    }

public:
    FloatAttr(float val) : valFloat(val), Attr("float") {}

    Attr *copy(void)
    {

        FloatAttr *retval = dynamic_cast<FloatAttr *>(this);

        return retval;
    }
    void print(){
        printf("%15f|",this->valFloat);
    }
    bool operator==(const Attr &right)
    {
        if (this->valFloat == dynamic_cast<const FloatAttr &>(right).valFloat)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(const Attr &right)
    {
        if (this->valFloat != dynamic_cast<const FloatAttr &>(right).valFloat)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(const Attr &right)
    {
        if (this->valFloat > dynamic_cast<const FloatAttr &>(right).valFloat)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>=(const Attr &right)
    {
        if (this->valFloat >= dynamic_cast<const FloatAttr &>(right).valFloat)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<(const Attr &right)
    {
        if (this->valFloat < dynamic_cast<const FloatAttr &>(right).valFloat)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<=(const Attr &right)
    {
        if (this->valFloat <= dynamic_cast<const FloatAttr &>(right).valFloat)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Record
{ // storing data for each record

private:
    vector<Attr *> attrptr;

public:
    Record(vector<Attr *> ptr)
    {
        for (int i = 0; i < ptr.size(); i++)
        {
            attrptr.push_back(ptr[i]->copy());
        }
    }
    void print()
    {
        printf("|");
        for (int i = 0; i < attrptr.size(); i++)
        {
            attrptr[i]->print();
        }
        printf("\n");
    }
    Record(const Record &Rec)
    {
        vector<Attr *> ptr = Rec.attrptr;
        for (int i = 0; i < ptr.size(); i++)
        {
            attrptr.push_back(ptr[i]->copy());
        }
    }

    void AddAnAttr(Attr *attri)
    {

        attrptr.push_back(attri->copy());
    }

    void AddVectAttr(vector<Attr *> vectri)
    {

        for (int i = 0; i < vectri.size(); i++)
        {
            attrptr.push_back(vectri[i]->copy());
        }
    }

    bool operator==(const Record &right)
    {
        if (this->attrptr.size() != right.attrptr.size())
        {
            return false;
        }

        int i = 0;
        for (int i = 0; i < this->attrptr.size(); i++)
        {
            if (*(this->attrptr[i]) == *(right.attrptr[i]))
            {

                continue;
            }

            break;
        }

        if (i == this->attrptr.size())
        {
            return true;
        }

        return false;

        ;
    }
    friend bool check_tuple(Record *ptr, int i, tuple<string, char, Attr *> condition);
    friend Relation *natural_joint(Relation *R1, Relation *R2, list<string> jointAttr);
    friend Relation;

    // constructor for cartesian product
    Record(const Record &R1, const Record &R2)
    {
        // Record *r3;
        vector<Attr *> ptr1 = R1.attrptr;
        vector<Attr *> ptr2 = R2.attrptr;

        for (int i = 0; i < ptr1.size(); i++)
        {
            attrptr.push_back(ptr1[i]->copy());
        }
        for (int i = 0; i < ptr2.size(); i++)
        {
            attrptr.push_back(ptr2[i]->copy());
        }
    }

    vector<Attr *> get_arr(void)
    {
        return attrptr;
    }
    // methods
};

class Relation
{ // storing a relation

private:
    int nattr, nrecs;     // number of attributes and records
    vector<int> attrinds; // mapping schema to indices
    list<Record *> recs;  // list of records

public:
    // methods
    vector<string> attrnames; // schema

    Relation(vector<string> schema) : nattr(schema.size()), nrecs(0)
    {
        attrnames.resize(nattr);

        for (int i = 0; i < attrnames.size(); i++)
        {

            attrnames[i] = schema[i];
        }
    }
    void print()
    {
        cout<<endl;
        for (int i = 0; i < nattr * 16 + 1; i++)
            printf("_");
        printf("\n");
        printf("|");
        for (int i = 0; i < nattr; i++)
            printf("%15s|", attrnames[i].c_str());
        printf("\n");
        for (int i = 0; i < nattr * 16 + 1; i++)
            printf("_");
        printf("\n");
        for (list<Record *>::iterator it = this->recs.begin(); it != this->recs.end(); it++)
            (*it)->print();
        for (int i = 0; i < nattr * 16 + 1; i++)
            printf("_");
        printf("\n");
    }
    Relation(vector<string> schema, list<string> projectattrs) : nattr(schema.size()), nrecs(0)
    {
    }
    void addRec(Record *ptr)
    {
        recs.push_back(new Record(*ptr));
        nrecs++;
        return;
    }

    void addRec(Relation *ptr)
    {

        for (list<Record *>::iterator it = this->recs.begin(); it != this->recs.end(); it++)
        {

            addRec(*it);
        }
    }

    bool find(Record *ptr)
    {
        for (list<Record *>::iterator it = this->recs.begin(); it != this->recs.end(); it++)
        {
            if (*ptr == **it)
            {
                return true;
            }

            return false;
        }
    }

    int find(list<string> attrs, string key)
    {

        int i = 0;
        for (list<string>::iterator it = attrs.begin(); it != attrs.end(); it++)
        {

            if (key == *it)
            {
                return i;
            }
            i++;
        }
        return -1;
    }

    /*void print(){
        cout<<endl;
        for (int i = 0; i < nattr * 16+1; i++)
        {
            printf("_");

        }
        printf("\n");
        printf("|");

        for(int i=0;i<nattr * 16+1;i++){
            printf("%15s|",attrnames[i].c_str());

        }

        printf("\n");

        for(list<Record*>::iterator it =this->recs.begin();it!=this->recs.end();it++){
            (*it)->print();

        }

        for (int i = 0; i < nattr * 16+1; i++)
        {
            printf("/n");

        }
        printf("\n");

    }*/

    //  member functions

    friend Relation *R_union(Relation *R1, Relation *R2);
    friend Relation *R_difference(Relation *R1, Relation *R2);
    friend Relation *R_catersianproduct(Relation *R1, Relation *R2);
    friend Relation *projection(Relation *R1, list<string> projectattrs);
    friend Relation *selection(Relation *R1, DNFformula *f);
    friend Relation *rename(Relation *R1, string s1, string s2);
    friend Relation *natJoi(Relation *R1, Relation *R2, list<string> jointattr);
    friend bool check(Record *ptr, Relation *R1,DNFformula* f);
};

Relation *R_union(Relation *R1, Relation *R2)
{
    Relation *R3 = new Relation(R2->attrnames);

    R3->addRec(R1);
    R3->addRec(R2);

    return R3;
}

Relation *R_difference(Relation *R1, Relation *R2)
{
    Relation *R3 = new Relation(R1->attrnames);

    for (list<Record *>::iterator it = R1->recs.begin(); it != R1->recs.end(); it)
    {
        if (!(R2->find(*it)))
        {
            R3->addRec(*it);
        }
    }

    return R3;
}

Relation *R_catersianproduct(Relation *R1, Relation *R2)
{

    Relation *R3 = new Relation(R1->attrnames);

    for (vector<string>::iterator it = R2->attrnames.begin(); it != R2->attrnames.end(); it++)
    {
        R3->attrnames.push_back(*it);
    }
    // schema defined

    for (list<Record *>::iterator it = R1->recs.begin(); it != R1->recs.end(); it++)
    {

        for (list<Record *>::iterator it1 = R2->recs.begin(); it1 != R2->recs.end(); it++)
        {
            // Record *newRec1 = new Record(**it);
            // Record *newRec2 = new Record(**it1);

            Record *Rx = new Record(**it, **it1);
        }
    }
}

Relation *projection(Relation *R1, list<string> projectattrs)
{
    vector<int> index;

    vector<string> ptr;
    for (vector<string>::iterator it = R1->attrnames.begin(); it != R1->attrnames.begin(); it++)
    {

        if (R1->find(projectattrs, (*it)) != -1)
        {
            ptr.push_back(*it);

            index.push_back(R1->find(projectattrs, (*it)));
        }
    } // ptr made

    Relation *R3 = new Relation(ptr); // schema defined

    for (list<Record *>::iterator it = R3->recs.begin(); it != R3->recs.end(); it++)
    {

        Record *rN = new Record(vector<Attr *>{});

        for (int i = 0; i < index.size(); i++)
        {

            rN->AddAnAttr((*it)->get_arr()[index[i]]);
        }

        R3->addRec(rN);
    }
    return R3;
}

bool check_tuple(Record *ptr, int i, tuple<string, char, Attr *> condition)
{
    Attr *tableattr = ptr->attrptr[i];
    char compare = get<1>(condition);
    Attr *compattr = get<2>(condition);

    switch (compare)
    {
    case '<':
        if ((tableattr[0] < compattr[0]))
        {
            return true;
        }
        return false;
        break;

    case '>':
        if ((tableattr[0] > compattr[0]))
        {
            return true;
        }
        return false;
        break;

    case '=':
        if ((tableattr[0] == compattr[0]))
        {
            return true;
        }
        return false;
        break;

    default:
        break;
    }

    cout << "please five a valid character !!!!" << endl;
}

bool check(Record *ptr, Relation *R1, DNFformula *f)
{

    for (list<list<tuple<string, char, Attr *>>>::iterator it = f->ops.begin(); it != f->ops.end(); it++)
    {

        int flag = 1;
        for (list<tuple<string, char, Attr *>>::iterator it1 = it->begin(); it1 != it->end(); it1++)
        {

            int index = -1;
            for (int i = 0; i < R1->attrnames.size(); i++)
            {

                if (R1->attrnames[i] == get<0>(*it1))
                {

                    index = i;
                }
            }

            if (check_tuple(ptr, index, (*it1)) == 0)
            {
                flag = 0;
            }

        }
        if (flag)
        {
            return true;
        }
    }

    return false;
}

Relation *selection(Relation *R1, DNFformula *f){

    Relation*res = new Relation(R1->attrnames);
    for(list<Record*>::iterator it =R1->recs.begin();it!=R1->recs.end();it++){
        if(check (*it,R1,f)){
            res->addRec(*it);
        }
        
    }
    return res;
}

Relation *rename(Relation *R1, string s1, string s2){

    for(int i=0; i<R1->attrnames.size(); i++){
        if(R1->attrnames[i]==s1){
            R1->attrnames[i]==s2;
        }
    }
    return R1;
}

Relation* natJoi(Relation *R1, Relation *R2, list<string>joinattr){
    DNFformula *f= new DNFformula;
    DNFformula *dnfformula=new DNFformula;

    for(list<Record*>::iterator it1 = R2->recs.begin(); it1 != R2->recs.end(); it1 ++){

        list<tuple<string,char, Attr*>> andformula;
        for(list<string>:: iterator it =joinattr.begin(); it != joinattr.end();it++){
            if(find(R1->attrnames.begin(),R1->attrnames.end(),*it)!=R1->attrnames.end()){
                string str =*it;
                char comp= '=';
                Attr* comp_para = (*it1)->get_arr()[find(R1->attrnames.begin(),R1->attrnames.end(),*it)-R1->attrnames.begin()];

                andformula.push_back(make_tuple(str, comp, comp_para));
                andformula.push_back(make_tuple(str+str, comp, comp_para));

            }
        }
        dnfformula->ops.push_back(andformula);
    }

    for (list<string>::iterator it = joinattr.begin();it != joinattr.end();it++){

        if (find(R1->attrnames.begin(),R1->attrnames.end(),*it)!=R1->attrnames.end()){
            rename(R2, (*it),(*it)+(*it));

        }
    }

    Relation* cart_rel = R_catersianproduct(R1,R2);
    //cart_rel->print();
    Relation *new_rel = selection(cart_rel, dnfformula);
    //new_rel->print()
    list<string> ls;

    for (int i = 0; i < R2->attrnames.size(); i++)
    {
        int flag = 1; 
        for (auto it = joinattr.begin() ;it!=joinattr.end(); it++)
        {
            if(*it+*it == R2->attrnames[i]){
                rename(R2,*(it),(*it)+(*it));
                flag= 0 ;
            }
            if(flag)
                ls.push_back(R2->attrnames[i]);
        }
        Relation* response = projection(new_rel,ls);
        return response;
    }
}
Attr *get_attr(string s)
{
    if (s == "integer")
    {
        int x;
        cin >> x;
        return new IntegerAttr(x);
    }
    if (s == "float")
    {
        float x;
        cin >> x;
        return new FloatAttr(x);
    }
    if (s == "string")
    {
        string x;
        cin >> x;
        return new StringAttr(x);
    }
}
Relation *inputRelation(void)
{
    cout << "\n- - : : creating a new table : : - -" ;
    int nattr, nrecs;
    cout << "Please enter number of rows : " << endl;
    cin >> nrecs;
    cout << "Please enter number of colomn : " << endl;
    cin >> nattr;
    vector<string> schema_name(nattr), schema_type(nattr);
    cout << "please enter the schema name and type(integer/float/string): " << endl;
    for (int i = 0; i < nattr; i++)
    {
        cout << "Schema " << i + 1 << " name : ";
        cin >> schema_name[i];
        cout << "Schema " << i + 1 << " type(integer/float/string) : ";
        cin >> schema_type[i];
    }

    Relation *relation = new Relation(schema_name);
    cout << "now please enter the records : " << endl;
    for (int i = 0; i < nrecs; i++)
    {
        vector<Attr *> attrptr;
        for (int j = 0; j < nattr; j++)
        {
            cout << "enter " << j + 1 << " attribute of " << i + 1 << " record( " << schema_type[j] << " ): ";
            Attr *ptr = get_attr(schema_type[j]);
            attrptr.push_back(ptr);
        }
        relation->addRec(new Record(attrptr));
    }
    // relation->print();
    return relation;
}

vector<Relation *> arr(10);
int i = 0;

int main()
{
    /*
    • Create    a new   empty table:    the user    can interactively   enter   the schema.
• Delete    an  existing    table   with    all data    in  it.
• Add   a   record  to  a   table.
• Print a table in  appropriate format.
• Create    a   table   from    existing    tables  using   the above   developed   operations.
    */
    // Relation* R1 = inputRelation();
    // Relation* R2 = inputRelation();
    while (1)
    {
        cout << "0-> quit" << endl;
        cout << "1-> add a new table" << endl;
        cout << "2-> delete table" << endl;
        cout << "3-> add a record to a table" << endl;
        cout << "4-> print a table" << endl;
        cout << "5-> creating a table from a existing table" << endl;
        int choice,x,y,subswitch,sz;
        cout << "\nenter your choice : ";
        cin >> choice;
        list<string> lt;
        set<string> st;

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            arr[i++] = inputRelation();
            break;
        case 2:
            cout << "Enter the index of the table to delete : " << endl;
            cin >> x;
            delete arr[x];
            while (x < i - 1)
            {
                arr[x] = arr[x + 1];
            }
            i--;
            break;
        case 3:
            cout << "Enter the index of the table to add record : " << endl;
            cin >> x;
            break;
        case 4:
            cout<<"Printing the table -->"<<endl;
            for (int j = 0; j < i; j++)
            {
                cout<<"\nTable at the index "<<j<<" is -"<<endl;
                arr[j]->print();
            }
            break;
        case 5:
            cout<<"Enter what operation you want to perform-->"<<endl;
            cout<<"50-->union of two relation "<<endl;
            cout<<"51-->difference of two relation"<<endl;
            cout<<"52-->cartesion product of two relation"<<endl;
            cout<<"53-->naturaljoin of two relation"<<endl;
            cout<<"Enter your choice: ";
            cin>>subswitch;
            cout<<"Enter the index of the element ";
            cin>>x>>y;
            switch (subswitch)
            {
            case 50:
                arr[i++]= R_union(arr[x],arr[y]);
                break;
            
            case 51:
                arr[i++]= R_difference(arr[x],arr[y]);
                break;
            case 52:
                arr[i++]= R_catersianproduct(arr[x],arr[y]);
                break;
            case 53:
                for(auto it:arr[x]->attrnames)
                    st.insert(it);
                for(auto it:arr[y]->attrnames){
                    sz = st.size();
                    st.insert(it);
                    if(sz==st.size())
                        lt.push_back(it);    
                }
                arr[i++] = natJoi(arr[x],arr[y],lt);
                break;
            default:
                break;
            }
        
        default:
            break;
        }
    }
    return 0;
}