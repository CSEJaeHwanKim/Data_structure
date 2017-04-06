//배열로 선언된 리스트
#include <iostream>
#define MAX 100//배열의 푀대값 선언을 위해 매크로 지정

using namespace std;
class List//class List선언
{
	int element[MAX];
	int m_length;
public:
	List(){m_length=0;}//생성자 함수
	~List(){}//소멸자 함수
	int GetLength(){return m_length;}//배열의 길이
	bool IsEmpty(){return (m_length==0);}//==if(m_length == 0){return true;}else{return false;} =>배열이 비어있는지 여부확인
	bool IsFull(){return (m_length == MAX);}//배열이 가득 차있는지 여부 확인
 	void Clear(){m_length=0;}//배열 초기화
	void AddHead(int item)//배열 첫번째에 인자 추가
	{
		if(!IsFull())//배열이 가득찼는지 여부 검사
		{
			for(int i=m_length-1;i>=0;i--)
			{
				element[i+1]=element[i];
			}
			m_length++;
			element[0]=item;//첫번째 요소에 추가
		}
	}
	void AddTail(int item)//배열의 마지막에 추가
	{
		if(m_length<MAX)//MAX값을 벗어나지 않는 조건에서 선언
		{
			element[m_length]=item;
			m_length+=1;
		}
		else
			printf("error\n");
	}
	void RePlace(int position,int item)//position위치에 인자값을 대체
	{
		if(position>=0&&position<=MAX)//MAX값을 벗어나지 않는 조건에서 선언
			element[position]=item;
		else if(position<0)
			printf("error\n");
		else
			printf("error\n");
	}
	int GetEntry(int position)//position위치에 있는 인자 출력
	{
		if(position>=0&&position<=MAX)
			return element[position];
		else
		{
			printf("error\n"); 
			return -1;
		}
	}
	bool IsInlist(int item)//값이 배열에 있는지 참 거짓 유무 확인
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
	void Display()//값의 출력
	{
		int i;
		for(i=0;i<m_length;i++)
		{
			printf("%d",element[i]);
		}
	}
	void Add(int position, int item)//값의 원하는 위치에 인자 추가
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
	void Delete(int position)//값의 삭제
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
