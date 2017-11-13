#include "assistance.h"	
#include "SeqList.h"	

int main(void)
{
	char c = '*';
    SeqList<int> la(6);
    int e, i;
    Status sta;
    
	while (c != '0')
	{
        cout << endl << "1. 生成线性表.";
        cout << endl << "2. 显示线性表.";
        cout << endl << "3. 取指定元素.";
        cout << endl << "4. 设置元素值.";
        cout << endl << "5. 删除元素.";
        cout << endl << "6. 插入元素.";
        cout << endl << "7. 元素定位.";
        cout << endl << "8. 求线性表长度.";
        cout << endl << "9. 找最大数和最小数.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~9):";
		cin >> c;
		switch (c) 	{
			case '1':
			    la.Clear();
			    sta = SUCCESS;
				cout << endl << "输入e(e = 0时退出):";
				cin >> e;
				while (e != 0 && sta != OVER_FLOW)	{
					sta = la.InsertElem(e);
					if (sta == OVER_FLOW) 
						cout << "线性表已满." << endl;
					else
						cin >> e;
				}
				la.OrderElem();
				break;
			case '2':
			    la.Traverse(Write<int>);
				break;
			case '3':
			    cout << endl << "输入元素位置:";
			    cin >> i;
			    if (la.GetElem(i, e) == NOT_PRESENT) 
					cout << "元素不存储." << endl;
				else
					cout << "元素:" << e << endl;
			    break;
			case '4':
			    cout << endl << "输入位置:";
			    cin >> i;
			    cout << endl << "输入元素值:";
			    cin >> e;
				if (la.SetElem(i, e) == RANGE_ERROR)
					cout << "位置范围错." << endl;
				else{
					cout << "设置成功." << endl;
					la.OrderElem();
                    }
			    break;
			case '5':
			    cout << endl << "输入位置:";
			    cin >> i;
			    if (la.DeleteElem(i, e) == RANGE_ERROR) 
					cout << "位置范围错." << endl;
				else
					cout << "被删除元素值:" << e << endl;
			    break;
			case '6':
			    cout << endl << "输入元素值:";
			    cin >> e;
			    sta = la.InsertElem(e);
				if (sta == OVER_FLOW) 
					cout << "线性表已满." << endl;
				else{
					cout << "插入成功." << endl;
                    la.OrderElem();	
                    }
			    break;
			case '7':
			    cout << endl << "输入元素值:";
			    cin >> e;
			    i = la.LocateElem(e); 
			    if (i != 0) 
					cout << "元素" << e << "的序号为：" << i << endl;
				else
					cout << "元素" << e << "不存在。"  << endl;
			    break;
			case '8':
			    cout << endl << "线性表的长度为:" << la.GetLength() << endl; 
			    break;
            case '9':
                cout << endl << "最大数的序号为：";
                i=la.Max()+1;
                cout << i;
                cout << endl << "最大数为：";
                if (la.GetElem(i, e) == ENTRY_FOUND) 
					cout << e << endl;   
                cout << endl << "最小数的序号为：";
                i=la.Min()+1;
                cout << i;
                cout << endl << "最小数为：";
                if (la.GetElem(i, e) == ENTRY_FOUND) 
					cout << e << endl;
			    break;
       	}
	}

   	system("PAUSE");        	 
   	return 0;               	
}


