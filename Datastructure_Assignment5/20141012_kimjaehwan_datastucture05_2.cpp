//�迭�� ����� ����Ʈ
#include <iostream>
#define MAX 100//�迭�� ǣ�밪 ������ ���� ��ũ�� ����

using namespace std;
class List//class List����
{
	int element[MAX];
	int m_length;
public:
	List(){m_length=0;}//������ �Լ�
	~List(){}//�Ҹ��� �Լ�
	int GetLength(){return m_length;}//�迭�� ����
	bool IsEmpty(){return (m_length==0);}//==if(m_length == 0){return true;}else{return false;} =>�迭�� ����ִ��� ����Ȯ��
	bool IsFull(){return (m_length == MAX);}//�迭�� ���� ���ִ��� ���� Ȯ��
 	void Clear(){m_length=0;}//�迭 �ʱ�ȭ
	void AddHead(int item)//�迭 ù��°�� ���� �߰�
	{
		if(!IsFull())//�迭�� ����á���� ���� �˻�
		{
			for(int i=m_length-1;i>=0;i--)
			{
				element[i+1]=element[i];
			}
			m_length++;
			element[0]=item;//ù��° ��ҿ� �߰�
		}
	}
	void AddTail(int item)//�迭�� �������� �߰�
	{
		if(m_length<MAX)//MAX���� ����� �ʴ� ���ǿ��� ����
		{
			element[m_length]=item;
			m_length+=1;
		}
		else
			printf("error\n");
	}
	void RePlace(int position,int item)//position��ġ�� ���ڰ��� ��ü
	{
		if(position>=0&&position<=MAX)//MAX���� ����� �ʴ� ���ǿ��� ����
			element[position]=item;
		else if(position<0)
			printf("error\n");
		else
			printf("error\n");
	}
	int GetEntry(int position)//position��ġ�� �ִ� ���� ���
	{
		if(position>=0&&position<=MAX)
			return element[position];
		else
		{
			printf("error\n"); 
			return -1;
		}
	}
	bool IsInlist(int item)//���� �迭�� �ִ��� �� ���� ���� Ȯ��
	{
		for(int i=0;i<m_length;i++)
		{
			if(element[i]==item)
				return true;
			else
				continue;
		}
		return false;
	}
	void Display()//���� ���
	{
		int i;
		for(i=0;i<m_length;i++)
		{
			printf("%d",element[i]);
		}
	}
	void Add(int position, int item)//���� ���ϴ� ��ġ�� ���� �߰�
	{
		if(!IsFull()&&(position>=0)&&position<=m_length)
		{
			for(int i=m_length-1;i>=position;i--)
			{
				element[i+1]=element[i];
				
			}
			m_length++;
			element[position]=item;
		}

	}
	void Delete(int position)//���� ����
	{
		int i;
		if(position<0||position>=m_length)
		{
			printf("error");
			return ;
		}
		for(i=position;i<(m_length-1);i++)
		{
			element[i]=element[i+1];
			m_length--;
		}
		
	}

};

int main()
{
   List list;

   printf(" 1. AddTail\n");
   list.AddTail( 1 );
   list.AddTail( 2 );
   list.AddTail( 3 );
   list.AddTail( 4 );

   list.Display();
   printf("\n");

   printf(" 2. AddHead\n");
   list.AddHead( 5 );
   list.AddHead( 6 );
   list.AddHead( 7 );

   list.Display();
   printf("\n");

   printf(" 3. Add\n");
   list.Add(3, 8);
   list.Add(5, 9);

   list.Display();
   printf("\n");

   printf(" 4. Clear\n");
   list.Clear();

   list.Display();
   printf("\n");

   printf(" 5. AddHead\n");
   list.AddHead(10);

   list.Display();
   printf("\n");
   
   printf(" 6. GetEntry(%d) : %d\n\n", 0, list.GetEntry(0));

   printf(" 7. GetLength : %d\n\n", list.GetLength());

   printf(" 8. IsEmpty : %s\n\n", list.IsEmpty() ? "Yes" : "No");

   printf(" 9. IsFull : %s\n\n", list.IsFull() ? "Yes" : "No");

   printf("10. IsInList(%d) : %s\n\n", 10, list.IsInlist(10) ? "Yes" : "No");

   printf("11. replace\n");
   list.RePlace(0, 11);

   list.Display();
   printf("\n");
   
   return 0;
}
