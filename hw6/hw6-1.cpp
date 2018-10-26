// CSCI1300 Fall 2018
// Author: QI WANG
// Recitation: <123> – <Your TA name>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk6




#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<iomanip>
#include<stdio.h>
#define SIZE 100
using namespace std;




/*int main()
{
    string file_book = "book.txt";
    string file_rating = "ratings.txt";


    string authors[SIZE];
    string titles[SIZE];

    int book_n;
    int arr_cp;

    //readBooks
    //readRatings
    //printAllBooks
    //getUserReadCount
    //calcAvgRating


    return 0;
}*/

char* getFileName_char(string fn)
{
    int size_fn = fn.length();

    char *p;
    p = (char*)malloc(sizeof(char)*(size_fn+1));
    fn.copy(p,size_fn,0);
    p[size_fn] = '\0';
    return p;
}

int findC(string str, char c)
{
    int size_str = str.length();
    if(size_str == 0)
    {
        return -1;
    }

    int i = 0;
    for(i = 0 ;i< size_str ; i++ )
    {
        if(str[i]==c)
        {
            return i;
        }
    }

    return -2;
}

int getNum(char c)
{
    if(c>'9'||c<'0')
    {
        return -1;
    }
    return c - '0';
}

/* split function
 * the function to split the given string into array of string with respect to a delimiter
 *
 * @param : string , the string we are going to split
 * @param : char, the delimiter
 * @param : string array, the array of string we save after spliting
 * @param : int, size of the  indicates the maximum number of split-apart string pieces
*/
 int split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }

/* readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: string, the name of the file to be read
 * @param: string array, titles
 * @param: string array, authors
 * @param: int, the number of books currently stored in the arrays
 * @param: int, capacity of the authors/titles arrays [assume to be 50]
 * @return: the total number of books in total
 */

int readBooks(string fn, string tts[], string aths[], int bk_n, int cp)
{

    char *file = getFileName_char(fn);

    ifstream in;
    in.open(file);
    if(!in.is_open())
    {
        in.close();
        return -1;
    }

    int cnt = 0;
    string nline = "";

    int mark;
    while(getline(in, nline)&&cnt<cp);
    {
        mark = findC (nline,',');
        if(mark>=0)
        {
            aths[cnt] = nline.substr(0,mark);
            mark++;
            tts[cnt] = nline.substr(mark,nline.length()-mark);
            cnt++;
        }

    }

    in.close();
    return cnt;
}
/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: string, the name of the file to be read
 * @param: string array, usernames
 * @param: 2D int array, list of ratings for each user (first index specifies user)
 * @param: int, the number of users currently stored in the array
 * @param: int, row capacity of the 2D array (convention: array[row][column]) [assume to be 100]
 * @param: int, column capacity of the 2D array [assume to be 50]
 * @return: the number of users in total
 */
int readRatings(string fn, string uns[], int usr_rts[100][100], int cp)
{
    char *file = getFileName_char(fn);

    fstream in;
    in.open(file);

    if(!in.is_open())
    {
        in.close();
        return -1;
    }

    int cnt = 0;
    string nline = "";

    string line_rt;
    int size_line_rt;
    int rt;
    int cnt_rt;

    int mark;
    while(getline(in,nline))
    {
        mark = findC (nline,',');
        if(mark>=0)
        {
            uns[cnt] = nline.substr(0,mark);
            mark++;
            line_rt = nline.substr(mark,nline.length());
            size_line_rt = line_rt.length();
            for(int i = 0 ; i<size_line_rt ; i++)
            {
                cnt_rt = 0;
                rt = getNum(line_rt[i]);
                if(rt!=-1)
                {
                    usr_rts[cnt][cnt_rt++] = rt;
                }
            }
            cnt++;
        }
    }

    in.close();
    return cnt;
}




void printAllBooks(string tts[], string aths[], int bk_n)
{
    for(int i=0 ; i<bk_n; i++)
    {
        cout << tts[i] << " by " << aths[i] <<endl;
    }
    return;
}

int getUserReadCount(string un, string usrs[], int usr_rts[100][100], int usr_n, int bk_n)
{
    int id = -1;
    for(int i = 0 ; i < usr_n ;i++)
    {
        if(un.compare(usrs[i])==0)
        {
            id = i;
        }
    }
    if(id == -1)
    {
        cout << un << " does not exist in the database" << endl;
        return -1;
    }

    int cnt = 0;
    for(int i = 0 ; i < bk_n ; i++)
    {
        if(usr_rts[id][i]>0)
        {
            cnt++;
        }
    }

    return cnt;
}

double calcAvgRating(string tt, string tts[], int usr_rts[100][100], int usr_n, int bk_n)
{
    int id = -1;
    for(int i = 0 ; i < bk_n ; i++ )
    {
        if(tt.compare(tts[i])==0)
        {
            id = i;
        }
    }
    if( id == -1 )
    {
        cout << tt << " does not exist in the database" << endl;
        return -1;
    }

    double ans = 0;

    int sum = 0;
    int cnt = 0;

    for(int i = 0 ; i < usr_n ; i++)
    {
        if(usr_rts[i][id]>0)
        {
            sum += usr_rts[i][id];
            cnt++;
        }
    }

    ans = sum / (cnt * 1.0);

    return ans;
}



/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Find number of books user rated" << endl;
  cout << "5. Get average rating" << endl;
  cout << "6. Quit" << endl;
}

int main(int argc, char const *argv[]) {
    string choice;
    int numBooks = 0;
    int numUsers = 0;

    string filename_books,filename_users;
    string username,booktitle;
    string titles[SIZE];
    string authors[SIZE];
    string users[SIZE];
    string ratings[SIZE][SIZE];

    while (choice != "6") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;

                    cin >> filename_books;

                    numBooks = readBooks(filename_books, titles, authors, numBooks , 50);

                    cout << "Total books in the database: " << numBooks << endl;
                    cout << endl;
                    break;

                case 2:
                    // read user file
                    cout << "Enter a raitng file name:" << endl;

                    cin << filename_users;

                    numUsers = readRatings(filename_users, users, ratings, 50);

                    cout << "Total users in the database: " << numUsers << endl;
                    cout << endl;
                    break;

                case 3:

                    printAllBooks();

                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;

                    cin >> username;

                    cout << username << " rating " << getUserReadCount(username, users, ratings, numUsers, numBooks) << " books";

                    cout << endl;
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;

                    cin << booktitle;

                    double r = calcAvgRating(booktitle, titles, ratings, numUser, numBooks);

                    cout << endl;
                    break;
                case 6:
                    // quit
                    cout << "good bye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
            }
    }

    return 0;
}

