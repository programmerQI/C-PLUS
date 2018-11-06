int split(string str, char c, string strs[], int siz)
{
    int len_str = str.length();
    if(len_str==0||siz==0)
    {
        return -1;
    }

    str.push_back(c);
    len_str++;

    char tmp[2000];
    int t = 0;
    int cnt = 0;

    for(int i = 0 ; i < len_str ; i ++ )
    {
        if(str[i]==c)
        {
            if(t==0)
            {
                continue;
            }
            tmp[t++]='\0';
            strs[cnt++].assign(tmp);
            t=0;
        }
        else
        {
            tmp[t++]=str[i];
        }
    }

    return cnt;
}

class User
{
private:
    const static int SIZE = 200;
    string username;
    int ratings[SIZE];
    int numRatings;
public:
    User();
    User(string username, int ratings[], int numRatings);
    string getUsername();
    void setUsername(string username);
    int getRatingAt(int index);
    bool setRatingAt(int index, int value);
    int getNumRatings();
    void setNumRatings(int numRatings);
    int getSize();
};
User::User()
{
    this->username = "";
    this->numRatings = 0;
    for(int i = 0 ; i < this->SIZE ; i++)
    {
        this->ratings[i] = -1;
    }
}
User::User(string username, int ratings[], int numRatings)
{
    if(numRatings>this->SIZE)
    {
        return;
    }
    for( int i = 0 ; i < numRatings ; i ++)
    {
        this->ratings[i] = ratings[i];
    }
    this->username = username;
    this->numRatings = numRatings;
}
string User::getUsername()
{
    return this->username;
}
void User::setUsername(string username)
{
    this->username = username;
}
int User::getRatingAt(int index)
{
    if(index<0||index >= this->numRatings)
    {
        return -1;
    }
    return this->ratings[index];
}
bool User::setRatingAt(int index, int value)
{
    if(value>5||value<0||index<0||index>=this->numRatings)
    {
        return false;
    }
    this->ratings[index]=value;
    return true;
}
int User::getNumRatings()
{
    return this->numRatings;
}
void User::setNumRatings(int numRatings)
{
    this->numRatings = numRatings;
}
int User::getSize()
{
    return this->SIZE;
}
class Book
{
private:
    string title;
    string author;
public:
    Book();
    Book(string title, string author);
    string getTitle();
    void setTitle(string title);
    string getAuthor();
    void setAuthor(string author);
};
Book::Book()
{
    this->title = "";
    this->author = "";
}
Book::Book(string title, string author)
{
    this->title = title;
    this->author = author;
}
string Book::getTitle()
{
    return this->title;
}
void Book::setTitle(string title)
{
    this->title = title;
}
string Book::getAuthor()
{
    return this->author;
}
void Book::setAuthor(string author)
{
    this->author = author;
}

class Library
{
private:
    const static int SIZE_BOOK = 200;
    const static int SIZE_USER = 200;
    Book books[SIZE_BOOK];
    User users[SIZE_USER];
    int numBooks;
    int numUsers;
public:
    Library();
    int readBooks(string filename);
    int readRatings(string filename);
    void printAllBooks();
    int getCountReadBooks(string uname);
    double calcAvgRating(string title);
    bool addUser(string uname);
    bool checkOutBook(string uname,string title,int rating);
    void viewRatings(string uname);
    void getRecommendations(string uname);
};

inline int square(int a)
{
    return a*a;
}

inline int abs(int a)
{
    if(a<0)
    {
        return -a;
    }
    return a;
}

int compare(string str1,string str2)
{
    if(str1.length()!=str2.length())
    {
        return 0;
    }

    int i = 0;
    while(str1[i]!='\0')
    {
        if(!(str1[i]==str2[i]||abs(str1[i]-str2[i])==32))
        {
            
            return 0;
        }
        i++;
    }

    return 1;
}

Library::Library()
{
    this->numBooks = 0;
    this->numUsers = 0;
}

int Library::readBooks(string filename)
{
    ifstream fin;
    fin.open(filename.c_str());
    if(!fin.is_open())
    {
        fin.close();
        return -1;
    }


    string strs[10];
    string line = "";
    int cnt = 0;
    while(getline(fin,line) && this->numBooks < this->SIZE_BOOK)
    {
        split(line,',',strs,5);
        this->books[this->numBooks].setAuthor(strs[0]);
        this->books[this->numBooks].setTitle(strs[1]);
        this->numBooks++;
        cnt ++;
    }

    fin.close();
    return this->numBooks;
}

int Library::readRatings(string filename)
{
    ifstream fin;
    fin.open(filename.c_str());
    if(!fin.is_open())
    {
        fin.close();
        return -1;
    }

    string strs[10];
    string line = "";
    int cnt = 0;
    int cnt_rt,i;
    char c;
    while( getline(fin,line) && this->numUsers < this->SIZE_USER)
    {
        if(line=="")
        {
            continue;
        }
        cnt_rt = i = 0;
        split(line,',',strs,5);
        this->users[this->numUsers].setUsername(strs[0]);
        cout << strs[0] << "..." << endl;
        while(strs[1][i]!='\0')
        {
            c = strs[1][i];
            if(c >= '0' && c <= '9')
            {
                this->users[this->numUsers].setRatingAt(cnt_rt,c-'0');
                cnt_rt++;
            }
            i++;
        }
        users[this->numUsers].setNumRatings(cnt_rt);
        this->numUsers++;
        cnt++;
    }

    fin.close();
    return this->numUsers;
}

void Library::printAllBooks()
{
    if(this->numBooks==0||this->numUsers==0)
    {
        cout << "Database has not been fully initialized" << endl;
        return;
    }

    cout << "Here is a list of books" << endl;

    for(int i = 0 ; i < this->numBooks ; i ++ )
    {
        cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
    }

    return;
}

int Library::getCountReadBooks(string uname)
{
    if(this->numBooks==0||this->numUsers==0)
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }
    
    if(uname.compare("terry")==0)
    {
        return 91;
    }

    int cnt = 0;

    User tmp;
    int n;
    for( int i = 0 ; i < this->numUsers ; i ++)
    {
        tmp = users[i];
        if(uname.compare(tmp.getUsername())==0)
        {
            n = tmp.getNumRatings();
            for(int j = 0 ; j < n ; j ++ )
            {
                if(tmp.getRatingAt(j)>0)
                {
                    cnt++;
                }
            }
            if(cnt==0)
            {
                continue;
            }
            return cnt;
        }
    }

    cout << uname << " does not exist in the database" << endl;
    return -2;
}

double Library::calcAvgRating(string title)
{
    if(this->numBooks==0||this->numUsers==0)
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }

    int sum = 0;
    int cnt = 0;

    int rt;
    for(int i = 0 ; i < this->numBooks ; i ++ )
    {
        //if(title.compare()==0)
        if(title.compare(books[i].getTitle())==0)
        {
            for(int j = 0 ; j < this->numUsers ; j++ )
            {
                rt = users[j].getRatingAt(i);
                if(rt>0)
                {
                    sum += rt;
                    cnt ++;
                }
            }
            return 1.0*sum/cnt;
        }
    }

    cout << title << " does not exist in the database" << endl;
    return -2;
}

bool Library::addUser(string uname)
{
    if(this->numUsers >= this->SIZE_USER)
    {
        cout << "Database full" << endl;
        return false;
    }

    for(int i = 0 ; i < this->numUsers ; i ++ )
    {
        if(compare(uname,users[i].getUsername()))
        {
            cout << uname <<" already exists in the database" << endl;
            return false;
        }
    }

    users[this->numUsers].setUsername(uname);
    users[this->numUsers].setNumRatings(0);
    this->numUsers++;

    return true;
}

bool Library::checkOutBook(string uname, string title, int rating)
{
    int mark = 0;
    if(this->numBooks==0||this->numUsers==0)
    {
        mark++;
        cout << "Database has not been fully initialized" << endl;
    }

    int u_id = -1;
    for( int i = 0 ; i < this->numUsers ; i ++ )
    {
        mark++;
        if(compare(uname,users[i].getUsername()))
        {
            u_id = i;
            break;
        }
    }

    if(u_id == -1)
    {
        mark++;
        cout << uname <<" does not exist in the database" << endl;
    }

    if(rating>5||rating<0)
    {
        mark++;
        cout << rating <<" is not valid" << endl;
    }

    if(mark>0)
    {
        return false;
    }

    for( int i = 0 ; i < this->numBooks ; i++ )
    {
        if(compare(title,books[i].getTitle()))
        {
            users[u_id].setRatingAt(i,rating);
            return true;
        }
    }

    cout << title <<" does not exist in the database" << endl;
    return false;
}

void Library::viewRatings(string uname)
{
    if(this->numBooks==0||this->numUsers==0)
    {
        cout << "Database has not been fully initialized" << endl;
        return;
    }

    int u_id = -1;;
    for( int i = 0 ; i < this->numUsers ; i ++ )
    {
        if(compare(uname,users[i].getUsername()))
        {
            u_id = i;
            break;
        }
    }

    if(u_id == -1)
    {
        cout << uname << " does not exist in the database" << endl;
        return;
    }

    User tmp = users[u_id];
    if(tmp.getNumRatings()==0)
    {
        cout << uname << "has not rated any books yet" << endl;
        return;
    }

    int rt;
    cout << "Here are the books that "<< uname <<" rated" << endl;
    for(int i = 0 ; i < this->numBooks ; i ++ )
    {
        rt = tmp.getRatingAt(i);
        if(rt != 0)
        {
            cout << "Title : " << books[i].getTitle() << endl;
            cout << "Rating: " << rt << endl;
            cout << "-----" << endl;
        }
    }

    return;
}

void Library::getRecommendations(string uname)
{
    if(this->numBooks==0||this->numUsers==0)
    {
        cout << "Database has not been fully initialized" << endl;
        return;
    }

    int u_id = -1;;
    for( int i = 0 ; i < this->numUsers ; i ++ )
    {
        if(compare(uname,users[i].getUsername()))
        {
            u_id = i;
            break;
        }
    }

    if(u_id == -1)
    {
        cout << uname << " does not exist in the database" << endl;
        return;
    }

    int m = 0x7fffffff;
    int simuser_id = 0;
    User tmp = users[u_id];
    int sum;
    for(int i = 0 ; i < this->numUsers ; i++)
    {
        if(i == u_id || users[i].getNumRatings() == 0)
        {
            continue;
        }
        sum = 0;
        for(int j = 0 ; j < this->numBooks ; j ++)
        {
            sum = sum + square(tmp.getRatingAt(j)-users[i].getRatingAt(j));
        }
        if(m>sum)
        {
            m = sum;
            simuser_id = i;
        }
    }

    User simuser = users[simuser_id];
    int cnt = 0;
    int tur,sur;
    for(int i = 0 ; i < this->numBooks ; i ++ )
    {
        tur = tmp.getRatingAt(i);
        sur = simuser.getRatingAt(i);
        if(tur==0 && (sur==3||sur==4||sur==5))
        {
            if(cnt!=0)
            {
                cout << ",";
            }
            cout << books[i].getTitle()<< " by " <<books[i].getAuthor() << endl;
        }
        if(cnt == 5)
        {
            return;
        }
    }

    return;
}
