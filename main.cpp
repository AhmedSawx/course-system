#include <iostream>
#include <limits>
using namespace std;

struct Course
{
  int id;
  string name;
  Course *next;
};

// prebulid Courses
void preCourse(Course *head)
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
Course *InsertLast(Course *head, string name)
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
  if (head == NULL)
  {
    cout << "Sorry it seems there is no corses in the system at the moment\n";
  }

  else if (head != NULL)
  {
    // choose order
    // system("cls"); // uncomment it when you find the right command!
    int sortType;
    cout << "1- Ascending\n";
    cout << "2- Descending\n";
    cin >> sortType;
    // normle Ascending
    if (sortType == 1)
    {
      while (head != NULL)
      {
        cout << "Course Id:" << head->id << endl;
        cout << "Course Name:" << head->name << endl;
        head = head->next;
      }
      return head;
    }
    // Revers Descending
    else if (sortType == 2)
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
      return head;
    }
    else
    {
      cout << "Wrong Input Please Restart and Enter a valid number\n";
    }
  }
}

Course *Modify(Course *head, string name, string newName)
{
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

Course *Search(Course *head)
{
  if (head == NULL)
  {
    cout << "Sorry it seems there is no corses in the system at the moment\n";
  }

  else
  {
    // way of search
    // system("cls"); // uncomment it when you find the right command!
    int searchType;
    cout << "1- Search by Corse ID\n";
    cout << "2- Search by Corse Name\n";
    cin >> searchType;

    // search by id
    if (searchType == 1)
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
            return head;
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
    else if (searchType == 2)
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
            return head;
          }
          else
          {
            head = head->next;
          }
        }
        cout << "No such corse has been found \n";
      }
    }
    else
    {
      cout << "Wrong Input Please Restart and Enter a valid number\n";
    }
  }
}
// ------ End Main Operations

// ------ Start Admin Operations
void addCourse(Course *head)
{
  string courseName;

  cout << "Enter Course Name: ";
  cin >> courseName;

  head = InsertLast(head, courseName);

  cout << "\nDone!\n\n";
}

void modifyCourse(Course *head)
{
  string courseName, newName;

  cout << "Enter Course Name: ";
  cin >> courseName;

  cout << "Enter New Name: ";
  cin >> newName;

  head = Modify(head, courseName, newName);

  cout << "\nDone!\n\n";
}

void deleteCourse(Course *head)
{
  string courseName;

  cout << "Enter Course Name: ";
  cin >> courseName;

  head = Delete(head, courseName);

  cout << "\nDone!\n\n";
}
// ------ End Admin Operations

// ------ Start Accounts
void user(Course *head)
{
  int choice;

  cout << "Choose what you want to do:\n\n";
  cout << "1- List all courses.\n";
  cout << "2- Search specific course.\n";
  cin >> choice;

  switch (choice)
  {
  case 1:
    Display(head);
    break;

  case 2:
    Search(head);
    break;

  default:
    cout << "Please Choose a right number.\n\n";
    break;
  }
}

void admin(Course *head)
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
      Display(head);
      break;

    case 2:
      Search(head);
      break;

    case 3:
      addCourse(head);
      break;

    case 4:
      modifyCourse(head);
      break;

    case 5:
      deleteCourse(head);
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
  Course *head = NULL;

  preCourse(head);

  while (true)
  {
    int choice = 0;

    cout << "Welcome to our Course System! Please choose who are you?\n";
    cout << "1- User\n2- Admin\n";

    // Check if the user's input is a valid number
    if (!(cin >> choice))
    {
      cout << "Invalid input. Please enter a number.\n\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    switch (choice)
    {
    case 1:
      user(head);
      return 0;

    case 2:
      admin(head);
      return 0;

    default:
      cout << "Please Choose a right number.\n\n";
      break;
    }
  }

  return 0;
}
