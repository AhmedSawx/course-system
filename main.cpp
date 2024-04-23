#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>

using namespace std;

#ifdef WINDOWS
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

struct Course
{
  int id;
  string name;
  Course *next;
};

int choiceDetect()
{
  int choice = 0;
  while (true)
  {
    // Check if the user's input is a valid number
    if (!(cin >> choice))
    {
      cout << "Invalid input. Please enter a number.\n\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    return choice;
  }
}

// ------ Start Main Operations
Course *InsertLast(Course *head, string name)
{
  Course *temp = new Course();
  temp->name = name;
  temp->id = 1;
  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
    return head;
  }

  Course *temp2 = head;
  temp->id++;
  while (temp2->next != NULL)
  {
    temp->id++;
    temp2 = temp2->next;
  }
  temp2->next = temp;
  return head;
}

void Display(Course *head)
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
    sortType = choiceDetect();
    // normle Ascending
    if (sortType == 1)
    {
      while (head != NULL)
      {
        cout << "Course Name: " << head->name << "\t";
        cout << "Course Id: " << head->id << endl;
        head = head->next;
      }
      return;
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
        cout << "Course Name: " << head->name << "\t";
        cout << "Course Id: " << head->id << endl;
        head = head->next;
      }
      return;
    }
    else
    {
      cout << "Wrong Input Please Restart and Enter a valid number\n";
    }
  }
}

Course *Modify(Course *head, string name, string newName)
{
  Course *temp = head;

  if (temp == NULL)
  {
    cout << "Sorry it seems there is no corses in the system at the moment\n";
  }

  while (temp != NULL)
  {
    if (temp->name == name)
    {
      temp->name = newName;

      cout << "\nDone!\n\n";
    }
    temp = temp->next;
  }

  return head; // handle warning
}

Course *Delete(Course *head, string name)
{
  Course *temp = head;
  Course *prev = NULL;

  if (temp == NULL)
  {
    cout << "Sorry it seems there is no corses in the system at the moment\n";
  }

  while (temp != NULL)
  {
    if (temp->name == name)
    {
      if (prev != NULL)
      {
        prev->next = temp->next;
        delete temp;
        cout << "\nDone!\n\n";

        return head;
      }
      else
      {
        head = temp->next;
        delete temp;
        cout << "\nDone!\n\n";

        return head;
      }
    }
    prev = temp;
    temp = temp->next;
  }

  return head; // handle warning
}

void search(Course *head)
{
  if (head == NULL)
  {
    cout << "Sorry it seems there is no corses in the system at the moment\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }

  else
  {
    // way of search
    // system("cls"); // uncomment it when you find the right command!
    system(CLEAR);
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
            cout << "the course has been found:\n"
                 << head->name << " ID: " << head->id << '\n';
            return;
          }
          else
          {
            head = head->next;
          }
        }
        cout << "No such course has been found \n";
      }

      else
      {
        cout << "Invalid input please restart\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        return;
      }
    }

    // search by name
    else if (searchType == 2)
    {

      if (head == NULL)
      {
        cout << "Sorry it seems there is no course in the system at the moment\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
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
            cout << "the course has been found:\n"
                 << head->name << "\nID: " << head->id << '\n';
            return;
          }
          else
          {
            head = head->next;
          }
        }
        cout << "No such course has been found \n";
      }
    }
    else
    {
      cout << "Wrong input. Please restart and Enter a valid number!\n";
    }
  }
}
// ------ End Main Operations

// prebulid Courses
Course *preCourse(Course *head)
{
  // first
  head = InsertLast(head, "Pieology");

  // second
  head = InsertLast(head, "Sciences");

  // third
  head = InsertLast(head, "Mathematics");
  return head;
}

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

  cout << "\t\tATTENTION PLAESE!!! the name should be 100% right\n";
  cout << "Please input course name: ";
  cin >> courseName;

  cout << "Enter new name: ";
  cin >> newName;

  head = Modify(head, courseName, newName);
}

void deleteCourse(Course *head)
{
  string courseName;

  cout << "Enter course name: ";
  cin >> courseName;

  head = Delete(head, courseName);
}
// ------ End Admin Operations

// ------ Start Accounts
void user(Course *head)
{
  while (true)
  {
    int choice;

    cout << "Choose what you want to do:\n\n";
    cout << "1- List all courses.\n";
    cout << "2- Search specific course.\n";
    cout << "0- Go back to menu\n";

    choice = choiceDetect();

    switch (choice)
    {
    case 1:
      Display(head);
      break;

    case 2:
      search(head);
      break;

    case 0:
      return;

    default:
      cout << "Please Choose a right number.\n\n";
      break;
    }
  }
}

void admin(Course *head)
{
  string password = "1221";
  string inputPass;
  cout << "INPUT THE PASSWORD: ";
  cin >> inputPass;

  if (password == inputPass)
  {
    while (true)
    {
      int choice;

      cout << "\n\t\tWelcome Admin!\n\n";
      cout << "Choose what you want to do:\n\n";
      cout << "1- List all courses.\n";
      cout << "2- Search specific course.\n";
      cout << "3- Add new course.\n";
      cout << "4- Modify specific course.\n";
      cout << "5- Delete course.\n";
      cout << "0- Go back to menu.\n";

      choice = choiceDetect();

      switch (choice)
      {
      case 1:
        Display(head);
        break;

      case 2:
        search(head);
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

      case 0:
        return;

      default:
        cout << "Please Choose a right number.\n\n";
        break;
      }
    }
  }
  else
  {
    system(CLEAR);
    cout << "Password incorrect!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return;
  }
}
// ------ End Accounts

int main()
{
  Course *head = nullptr;

  head = preCourse(head);

  while (true)
  {
    int choice = 0;

    cout << "\nWelcome to our Course System! Please choose who are you?\n";
    cout << "1- User\n2- Admin\n";

    choice = choiceDetect();

    cout << endl;

    switch (choice)
    {
    case 1:
      user(head);
      break;

    case 2:
      admin(head);
      break;

    default:
      cout << "Please Choose a right number.\n\n";
      break;
    }
  }

  return 0;
}
