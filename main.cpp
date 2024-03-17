#include <iostream>
using namespace std;

struct Course
{
  int id;
  string name;
  Course *next;
};

Course *head = NULL;

// prebulid Courses
void preCourse()
{
  // first
  struct Course *pieology = new Course();
  head = pieology;
  pieology->id = 1;
  pieology->name = "Pieology";

  // second
  struct Course *sciences = new Course();
  pieology->next = sciences;
  sciences->id = 2;
  sciences->name = "Sciences";

  // third
  struct Course *math = new Course();
  sciences->next = math;
  math->id = 3;
  math->name = "Mathematics";
  math->next = NULL;
}

// ------ Start Main Operations
Course *Insert(Course *head, string name)
{
  int id = 0;
  Course *temp = new Course();
  temp->name = name;
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
    return head;
  }

  Course *temp2 = head;
  while (temp2->next != NULL)
  {
    temp2 = temp2->next;
    temp2->id++;
  }
  temp2->next = temp;
  return head;
}

Course *Display(Course *head)
{
  Course *temp = head;

  cout << "ID "
       << "Name " << endl;

  while (temp != NULL)
  {
    cout << temp->id << " ";
    cout << temp->name << endl;
    temp = temp->next;
  }

  return head;
}

Course *Delete(Course *head, string name)
{
  Course *temp = head;
  Course *prev = NULL;
  while (temp != NULL)
  {
    if (temp->name == name)
    {
      if (prev != NULL)
      {
        prev->next = temp->next;
        delete temp;
        return head;
      }
      else
      {
        head = temp->next;
        delete temp;
        return head;
      }
    }
    prev = temp;
    temp = temp->next;
  }
}
// ------ End Main Operations

// ------ Start User Operations
void list()
{
  if (head == NULL)
  {
    cout << "Sorry it seems there is no corses in the system at the moment\n";
  }

  else if (head != NULL)
  {
    // choose order
    system("cls");
    int printCh;
    cout << "1-Ascending\n";
    cout << "2-Descending\n";
    cin >> printCh;
    // normle Ascending
    if (printCh == 1)
    {
      while (head != NULL)
      {
        cout << "Course Id:" << head->id << endl;
        cout << "Course Name:" << head->name << endl;
        head = head->next;
      }
    }
    // Revers Descending
    else if (printCh == 2)
    {
      Course *current = head;
      Course *prev = NULL;
      Course *next = NULL;

      while (current != NULL)
      {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
      }
      head = prev;

      while (head != NULL)
      {
        cout << "Course Id:" << head->id << endl;
        cout << "Course Name:" << head->name << endl;
        head = head->next;
      }
    }
    else
    {
      cout << "Invalide input please restart\n";
    }
  }
}

void search()
{
  if (head == NULL)
  {
    cout << "Sorry it seems there is no corses in the system at the moment\n";
  }

  else
  {
    // way of search
    system("cls");
    int searchCo;
    cout << "1-Search by Corse ID\n";
    cout << "2-Search by Corse Name\n";
    cin >> searchCo;

    // search by id
    if (searchCo == 1)
    {
      int theId;
      cout << "please input the id:";
      cin >> theId;
      if (theId != 0)
      {

        while (head != NULL)
        {
          if (theId == head->id)
          {
            cout << "the corse has been found :" << head->name << " ID:" << head->id;
            return;
          }
          else
          {
            head = head->next;
          }
        }
        cout << "No such corse has been found \n";
      }

      else
      {
        cout << "Invalid input please restart\n";
        return;
      }
    }

    // search by name
    else if (searchCo == 2)
    {

      if (head == NULL)
      {
        cout << "Sorry it seems there is no corses in the system at the moment\n";
      }

      else
      {
        string theName;
        cout << "\t\tATTENTION PLAESE!!! the name should be 100% right\n";
        cout << "please input the name:";
        cin >> theName;

        while (head != NULL)
        {
          if (theName == head->name)
          {
            cout << "the corse has been found :" << head->name << " ID:" << head->id;
            return;
          }
          else
          {
            head = head->next;
          }
        }
        cout << "No such corse has been found \n";
      }
    }
  }
}
// ------ End User Operations

// ------ Start Admin Operations
void addCourse()
{
}

void modifyCourse()
{
}

void deleteCourse()
{
}
// ------ End Admin Operations

// ------ Start Accounts
void user()
{
  int choice;

  cout << "Choose what you want to do:\n\n";
  cout << "1- List all courses.\n";
  cout << "2- Search specific course.\n";
  cin >> choice;

  switch (choice)
  {
  case 1:
    list();
    break;

  case 2:
    search();
    break;

  default:
    cout << "Please Choose a right number.\n\n";
    break;
  }
}

void admin()
{
  int password = 1221;
  int inputPass;
  cout << "INPUT THE PASSWORD: ";
  cin >> inputPass;

  if (password == inputPass)
  {
    int choice;

    cout << "\n\t\tWelcome Admin!\n\n";
    cout << "Choose what you want to do:\n\n";
    cout << "1- List all courses.\n";
    cout << "2- Search specific course.\n";
    cout << "3- Add new course.\n";
    cout << "4- Modify specific course.\n";
    cout << "5- Delete course.\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
      list();
      break;

    case 2:
      search();
      break;

    case 3:
      addCourse();
      break;

    case 4:
      modifyCourse();
      break;

    case 5:
      deleteCourse();
      break;

    default:
      cout << "Please Choose a right number.\n\n";
      break;
    }
  }
  else
  {
    cout << "YOU ARE FAKE!\n";
  }
}
// ------ End Accounts

int main()
{
  int choice = 0; // Handle if user insert a String or anything else except number

  preCourse();

  while (true)
  {
    cout << "Welcome to our Course System! Please choose who are you?" << '\n';
    cout << "1- User\n2- Admin\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
      user();
      exit(0);
      break;

    case 2:
      admin();
      exit(0);
      break;

    default:
      cout << "Please Choose a right number.\n\n";
      break;
    }
  }

  return 0;
}
