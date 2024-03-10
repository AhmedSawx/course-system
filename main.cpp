#include <iostream>
using namespace std;

struct Course
{
  int id;
  string name;
  Course *next;
};

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

int main()
{

  Course *head = NULL;
  int choice = 0;

  while (true)
  {
    cout << "Welcome to our Course System! Please choose" << '\n';
    cout << "1-User\n2-Admin\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
      break;
    case 2:
      break;
    default:
      break;
    }
  }

  return 0;
}
