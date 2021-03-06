#include<stdio.h>
#include<conio.h>
#include<math.h>
struct node
{
 int cf,px,py,pz;
 struct node *link;
};
typedef struct node *NODE;
NODE attach(int c1,int e1,int e2,int e3,NODE head)
{
 NODE temp,cur;
 temp=(struct node*)malloc(sizeof(struct node));
 temp->cf=c1;
 temp->px=e1;
 temp->py=e2;
 temp->pz=e3;
 cur=head->link;
 while(cur->link!=head)
 cur=cur->link;
 cur->link=temp;
 temp->link=head;
 return head;
}
NODE readpoly(NODE head)
{
 int c1,e1,e2,e3,i=1;
 while(1)
 {
 printf("enter %dth tern\n",i++);
 printf("enter coeff\n");
 scanf("%d",&c1);
 if(c1==999)break;
 printf("enter exponents\n");
 scanf("%d%d%d",&e1,&e2,&e3);
 head=attach(c1,e1,e2,e3,head);
 }
 return head;
}
NODE search(NODE p1,NODE h2)
{NODE p2;
 int px1,py1,pz1,px2,py2,pz2;
 px1=p1->px;
 py1=p1->py;
 pz1=p1->pz;
 p2=h2->link;
 while(p2!=h2)
 {
  px2=p2->px;py2=p2->py;pz2=p2->pz;
  if(px1==px2&&py1==py2&&pz1==pz2)break;
  p2=p2->link;
 }
 return p2;
}
NODE polyadd(NODE h1,NODE h2,NODE h3)
{
 NODE a,b;
 int cf1,px1,py1,pz1,sum=0;
 a=h1->link;
 while(a!=h1)
 {
  cf1=a->cf;px1=a->px;py1=a->py;pz1=a->pz;
  b=search(a,h2);
  if(b!=h2)
  {
   sum=cf1+b->cf;
   h3=attach(sum,px1,py1,pz1,h3);
   b->cf=999;
  }
  else
  {
   h3=attach(cf1,px1,py1,pz1,h3);
  }
  a=a->link;
 }
 b=h2->link;
 while(b!=h2)
 {
  if(b->cf!=999)
  {
   h3=attach(b->cf,b->px,b->py,b->pz,h3);
  }
  b=b->link;
 }
 return h3;
}
double evaluate(NODE head)
{
 int x,y,z;double sum=0;
 NODE p;
 printf("enter values of x,y,z\n");
 scanf("%d%d%d",&x,&y,&z);
 p=head->link;
 while(p!=head)
 {
  sum+=p->cf*pow(x,p->px)*pow(y,p->py)*pow(z,p->pz);
  p=p->link;
 }
 return sum;
}
void display(NODE head)
{
 NODE temp;
 temp=head->link;
 while(temp!=head)
 {
  if(temp->cf<0)
   printf("%dx^%dy^%dz^%d",temp->cf,temp->px,temp->py,temp->pz);
  else
   printf("+%dx^%dy^%dz^%d",temp->cf,temp->px,temp->py,temp->pz);
  temp=temp->link;
 }
 printf("\n");
}
void main()
{double res;
 int ch;
 NODE head1,head2,head3;
 clrscr();
 while(1)
 {
  printf("1poly addition 2 poly evaluation\n");
  printf("enter choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:head1=(struct node*)malloc(sizeof(struct node));
	  head2=(struct node*)malloc(sizeof(struct node));
	  head3=(struct node*)malloc(sizeof(struct node));
	  head1->link=head1;
	  head2->link=head2;
	  head3->link=head3;
	  printf("enter 1st poly\n");
	  head1=readpoly(head1);
	  printf("enter 2nd poly\n");
	  head2=readpoly(head2);
	  printf("1st poly is\n");
	  display(head1);
	  printf("2nd poly is\n");
	  display(head2);
	  head3=polyadd(head1,head2,head3);
	  printf("resultant poly is\n");
	  display(head3);
	  break;
   case 2:head1=(struct node*)malloc(sizeof(struct node));
   head1->link=head1;
   printf("enter poly\n");
   head1=readpoly(head1);
   res=evaluate(head1);
   printf("result is %lf\n",res);
   break;
   default:exit(0);
  }
 }
}
