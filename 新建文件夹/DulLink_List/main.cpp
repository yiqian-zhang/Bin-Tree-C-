#include "Assistance.h"	// �������������
#include "Dbllinklist.h"	// ˫��ѭ��������
 
int main(void)
{
    char c = '1';
    DblLinkList<double> la,lb;
    double e;
    int i;

    while (c != '0')	{
        cout << endl << "1. �������Ա�.";
        cout << endl << "2. ��ʾ���Ա�.";
        cout << endl << "3. ȡָ��Ԫ��ֵ.";
        cout << endl << "4. ����Ԫ��ֵ.";
        cout << endl << "5. ɾ��Ԫ��.";
        cout << endl << "6. ����Ԫ��.";
        cout << endl << "7. Ԫ�ض�λ.";
        cout << endl << "8. �������ֵ��Сֵ.";
        cout << endl << "0. �˳�";
        cout << endl << "ѡ����(0~8):";
        cin >> c;
    switch (c) 	{
     case '1':
          la.Clear();
          cout << endl << "����e(e = 0ʱ�˳�):";
          cin >> e;    
          while (e != 0)	{
                //if(la.GetLength()==0) 
                //la.InsertElem(e);
				//else 
                la.insertNode(e);
				cin >> e;		
          }
     break;
     case '2':
          lb = la;
          lb.Traverse(Write<double>);
     break;
     case '3':
          cout << endl << "����Ԫ��λ��:";
          cin >> i;
          if (la.GetElem(i, e) == NOT_PRESENT) 
             cout << "Ԫ�ز��洢." << endl;
          else
             cout << "Ԫ��:" << e << endl;
     break;
     case '4':
          cout << endl << "����λ��:";
          cin >> i;
          cout << endl << "����Ԫ��ֵ:";
          int x;
          cin >> x;
          if (la.DeleteElem(i, e) == RANGE_ERROR)
             cout << "λ�÷�Χ��." << endl;
          else
          {
             cout << "���滻Ԫ��ֵ." << e << endl;
             la.insertNode(x);
          }
     break;
     case '5':
          cout << endl << "����λ��:";
          cin >> i;
          if (la.DeleteElem(i, e) == RANGE_ERROR) 
             cout << "λ�÷�Χ��." << endl;
          else
             cout << "��ɾ��Ԫ��ֵ:" << e << endl;
     break;
     case '6':
          //cout << endl << "����λ��:";
	      //cin >> i;
	      cout << endl << "����Ԫ��ֵ:";
	      cin >> e;
	      la.insertNode(e); 
          cout << "�ɹ�:" << e << endl;
     break;
     case '7':
          cout << endl << "����Ԫ��ֵ:";
          cin >> e;
          i = la.LocateElem(e);
          if (i == 0) 
             cout << "ָ��Ԫ�ز�����." << endl;
          else
             cout << "ָ��Ԫ�ص����Ϊ��" << i << endl;
     break;	
     case'8':
                //int i=la.FindMax();
                //if(la.GetElem(i,e)==ENTRY_FOUND)
          double max=la.FindMax();
          double min=la.FindMin();
          cout << endl << "���ֵΪ��" << max << endl;;
          cout << endl << "��СֵΪ��" << min << endl;
                
          int i1=la.LocateElem(max),i2=la.LocateElem(min);
          la.swapNodes(i1,i2); 
          //cout<<i<<endl;
          //cout<<i1<<" "<<i2;
                
          cout << endl << "�����ɹ�" << endl;
          break;
          }
}

system("PAUSE");	
return 0;	
}
