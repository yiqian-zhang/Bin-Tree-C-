#ifndef __DBL_LK_LIST_H__
#define __DBL_LK_LIST_H__

#include "Dblnode.h"	// ˫����������

// ˫��������
template <class ElemType>
class DblLinkList 
{
protected:
//  ѭ����������ݳ�Ա:
DblNode<ElemType> *head;	// ͷ���ָ��
int length;	// Ԫ�ظ���

public:
DblLinkList();	        // �޲����Ĺ��캯��
DblLinkList(ElemType v[], int n);	// �в����Ĺ��캯��
 	virtual ~DblLinkList();	        // ��������
int GetLength() const;	    // ��ѭ��������	 
bool IsEmpty() const;	    // �ж�ѭ�������Ƿ�Ϊ��
void Clear();	        // ��ѭ���������
void Traverse(void (*Visit)(const ElemType &)) const;// ����ѭ������
int LocateElem(const ElemType &e);	// Ԫ�ض�λ 
Status GetElem(int i, ElemType &e) const;	 // ȡָ��λ�õ�Ԫ��	
Status SetElem(int i, const ElemType &e);	// ����ָ��λ�õ�Ԫ��ֵ
Status DeleteElem(int i, ElemType &e);	// ɾ��Ԫ��	
Status InsertElem(int i, const ElemType &e);// ������λ�ò���Ԫ��
Status InsertElem(const ElemType &e);	    // �ڱ�β����Ԫ��
DblLinkList(const DblLinkList<ElemType> &la);// ���ƹ��캯��
DblLinkList<ElemType> &operator =(const DblLinkList<ElemType> &la); // ���ظ�ֵ���� 
ElemType FindMax();
ElemType FindMin();
void swapNodes(int v1, int v2);
void insertNode(const ElemType& e); 
};

template <class ElemType>
ElemType DblLinkList<ElemType>::FindMax(){
         DblNode<ElemType> *p=head->next;
         ElemType t=head->next->data;
         for(int i=1;i<length;i++)
         {
            p=p->next;
            if(p->data>t) t=p->data;
         }
         return t;
}
template <class ElemType>
ElemType DblLinkList<ElemType>::FindMin(){
         DblNode<ElemType> *p=head->next;
         ElemType t=head->next->data;
         for(int i=1;i<length;i++)
         {
            p=p->next;
            if(p->data<t) t=p->data;
         }
         return t;
}

template <class ElemType>
void  DblLinkList<ElemType>::swapNodes(int v1, int v2){
         DblNode<ElemType> *p=head->next,*p1;
         DblNode<ElemType> *q=head->next,*q1,*t;
         int x;
         //int i1=LocateElem(v1),i2=1;
         if(v1>v2){x=v1;v1=v2;v2=x;}
         for(int i=1;i<v1;i++) p=p->next;
         for(int j=1;j<v2;j++) q=q->next;
         //while(p != head && p->data != v1) {p=p->next;//i1++;}
         //while(q != head && q->data != v2) {q=q->next;i2++;}
         x=v2-v1;
         p1=p->prior; q1=q->next;
         if(x==1)
         {
             p->prior->next=q; q->prior=p->prior;
             q->next->prior=p; p->next=q->next;
             q->next=p;
             p->prior=q;
             
         }
         else
         {
         p->prior->next=q;
         q->next->prior=p;
         p->next->prior=q;
         q->prior->next=p;
         p->prior=q->prior;
         q->next=p->next;
         p->next=q1;
         q->prior=p1;
         }
}

template <class ElemType>
DblLinkList<ElemType>::DblLinkList()
// �������������һ��������
{
head = new DblNode<ElemType>;	// ����ͷָ��
assert(head);                   // ����ͷ���ʧ�ܣ���ֹ�������� 
head->prior = head->next = head;// ��ѭ������ͷ����ǰ�������Ϊͷ��㱾��
length = 0;	// ��ʼ��Ԫ�ظ���
}

template <class ElemType>
DblLinkList<ElemType>::DblLinkList(ElemType v[], int n)
// �����������������v�е�Ԫ�أ�����˫��ѭ������
{
    DblNode<ElemType> *p;
p = head =  new DblNode<ElemType>;	// ����ͷ��� 
assert(head);                       // ����ͷ���ʧ�ܣ���ֹ�������� 
for (int i = 0; i < n; i++) {
    p->next = new DblNode<ElemType>(v[i],p);
    assert(p->next);                // ����Ԫ�ؽ��ʧ�ܣ���ֹ�������� 
    p = p->next;
    }
length = n;	    // ��ʼ��Ԫ�ظ���
    head->prior = p;                    //ͷ����priorָ��β��� 
    p->next = head;	                    //β����nextָ��ͷ��� 
}

template <class ElemType>
DblLinkList<ElemType>::~DblLinkList()
// �������������ѭ������
{
Clear();	// ���ѭ������
delete head;	// �ͷ�ͷ���ռ�
}

template <class ElemType>
int DblLinkList<ElemType>::GetLength() const
// �������������ѭ������Ԫ�ظ���
{
return length;
}

template <class ElemType>
bool DblLinkList<ElemType>::IsEmpty() const
// �����������ѭ������Ϊ�գ��򷵻�true�����򷵻�false
{
return head->next == head;
}

template <class ElemType>
void DblLinkList<ElemType>::Clear()
// ������������ѭ������
{

ElemType tmpElem;	// ��ʱԪ��ֵ
while (length > 0)	// ѭ������ǿգ���ɾ����1��Ԫ��
DeleteElem(1, tmpElem);
}

template <class ElemType>
void DblLinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// ������������ζ�ѭ�������ÿ��Ԫ�ص��ú���(*visit)
{
    DblNode<ElemType> *p;
for (p = head->next; p != head; p = p->next)	// ��p���η���ÿ��Ԫ��
(*Visit)(p->data);	// ��ѭ�������ÿ��Ԫ�ص��ú���(*visit)
}

template <class ElemType>
int DblLinkList<ElemType>::LocateElem(const ElemType &e)
// �������������ָ��Ԫ����ѭ�������е�һ�γ��ֵ���ţ���������ڷ���0 
{
    DblNode<ElemType> *p = head->next;
    int count=1;
while (p != head && p->data != e) {
    count++;
p = p->next;
}
if (p != head)
    return count;
    else 
        return 0;
}

template <class ElemType>
Status DblLinkList<ElemType>::GetElem(int i, ElemType &e) const
// �����������ѭ��������ڵ�i��Ԫ��ʱ����e������ֵ����������ENTRY_FOUND,
//	����������NOT_PRESENT
{
    DblNode<ElemType> *p = head->next;
    int count;
if (i < 1 || i > length)	// i��Χ��
return NOT_PRESENT;	
else	{	// i�Ϸ�
for (count = 1; count < i; count++)
  p = p->next;	            // pָ���i�����	
e = p->data;	// ��e���ص�i��Ԫ�ص�ֵ
return ENTRY_FOUND;
}
}

template <class ElemType>
Status DblLinkList<ElemType>::SetElem(int i, const ElemType &e)
// �����������ѭ������ĵ�i��λ�õ�Ԫ�ظ�ֵΪe,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
    DblNode<ElemType> *p = head->next;
    int count;
if (i < 1 || i > length)
return RANGE_ERROR;
else	{	// i�Ϸ�
for (count = 1; count < i; count++)
  p = p->next;	// pָ���i�����	
p->data = e;	// ���õ�i��Ԫ�ص�ֵ
return SUCCESS;
}
}

template <class ElemType>
Status DblLinkList<ElemType>::DeleteElem(int i, ElemType &e)
// ���������ɾ��ѭ������ĵ�i��λ�õ�Ԫ��, ����e������ֵ,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
    DblNode<ElemType> *p = head->next;
    int count;
if (i < 1 || i > length)
return RANGE_ERROR;
else	{	// i�Ϸ�
     for (count = 1; count < i; count++)
  p = p->next;	// pָ���i�����	
p->prior->next = p->next;	// p��ǰ������nextָ��p���ĺ�̽�� 
p->next->prior = p->prior;	// p�ĺ�̽���priorָ��p����ǰ�����
e = p->data;	// ��e���ر�ɾ���Ԫ��ֵ	
length--;	// ɾ���ɹ���Ԫ�ظ�����1 
delete p;	    // �ͷű�ɾ���
return SUCCESS;
}
}

template <class ElemType>
void DblLinkList<ElemType>::insertNode(const ElemType& e) { 
               DblNode<ElemType>* p=head->next;
               while(e < p->data)
                  p=p->next;
               DblNode<ElemType>* q = new DblNode<ElemType>(e, p->prior, p);
		       p->prior->next = q;			
		       p->prior = q;				
		       length++;					
} 



/*template <class ElemType>
Status DblLinkList<ElemType>::InsertElem(int i, const ElemType &e)
// �����������ѭ������ĵ�i��λ��ǰ����Ԫ��e
//	i��ȡֵ��ΧΪ1��i��length+1
//	i�Ϸ�ʱ����SUCCESS, ����������RANGE_ERROR
{
    DblNode<ElemType> *p = head->next,*q;
    int count;
	if (i < 1 || i > length + 1)	// i��Χ��,λ�ò��Ϸ�
		return RANGE_ERROR; 
	else	{	// i�Ϸ�
		for (count = 1; count < i; count++)
		  p = p->next;	// pָ���i�����	
		q = new DblNode<ElemType>(e, p->prior, p);// �����½��q
		p->prior->next = q;			// p��ǰ������nextָ��q���
		p->prior = q;				// p��priorָ��q���
		length++;					// ����ɹ���Ԫ�ظ�����1 
		return SUCCESS;
	}
}*/

template <class ElemType>
Status DblLinkList<ElemType>::InsertElem(const ElemType &e)
// �����������ѭ������ı�β����Ԫ��e
{
    DblNode<ElemType> *p;
	p = new DblNode<ElemType>(e, head->prior,head);// �����½��
	assert(p);                   	// ����Ԫ�ؽ��ʧ�ܣ���ֹ�������� 
	head->prior->next = p;			// ԭβ����nextָ��p���
	head->prior = p;				// ͷ���priorָ��q���
	length++;						// ����ɹ���Ԫ�ظ�����1 
	return SUCCESS;
}

template <class ElemType>
DblLinkList<ElemType>::DblLinkList(const DblLinkList<ElemType> &la)
// ������������ƹ��캯�����ɵ�����la�����µ�����
{
int laLength = la.GetLength();	// ȡ�����Ƶ�����ĳ���
ElemType e;
head = new DblNode<ElemType>;	// ����ͷָ��
assert(head);                   // ����ͷָ��ʧ�ܣ���ֹ�������� 
length = 0;	// ��ʼ��Ԫ�ظ���

for (int i = 1; i <= laLength; i++)	{	// ��������Ԫ��
la.GetElem(i, e);	// ȡ����i��Ԫ�ص�ֵ����e�� 
InsertElem(e);	// ��e���뵽��ǰ������ı�β 
}
}

template <class ElemType>
DblLinkList<ElemType> &DblLinkList<ElemType>::operator =(const DblLinkList<ElemType> &la)
// ������������ظ�ֵ���������������la��ֵ����ǰ������
{
if (&la != this)	{
int laLength = la.GetLength();// ȡ����ֵ������ĳ���
ElemType e;
Clear();	// ��յ�ǰ������
for (int i = 1; i <= laLength; i++)	{
la.GetElem(i, e);	    // ȡ����i��Ԫ�ص�ֵ����e��
InsertElem(e);	            // ��e���뵽��ǰ������ı�β
}
}
return *this;
}

#endif
