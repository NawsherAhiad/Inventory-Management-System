#include <bits/stdc++.h>
using namespace std;

struct Tools   ///Node
{
    int Tool_no, category_no, price;
    struct Tools *link;
}*node_tool;

struct Customer   ///Node
{
    int customer_no, tool_order, category_order, order_month;
    struct Customer *link;
}*node_customer;

struct SoldTools   ///Node
{
    int Tool_no, category_no, price, order_month, customer_info;
    struct SoldTools *link;
}*node_sold_tool;



struct Head1
{
    struct Tools *p;
}*head1;

struct Head2
{
    struct Customer *p;
}*head2;

struct Head3
{
    struct SoldTools *p;
}*head3;



void createHead1()
{
    head1 = (struct Head1*)malloc(sizeof(struct Head1));
    head1->p = NULL;

}
void createHead2()
{
    head2 = (struct Head2*)malloc(sizeof(struct Head2));
    head2->p = NULL;

}
void createHead3()
{
    head3 = (struct Head3*)malloc(sizeof(struct Head3));
    head3->p = NULL;

}



void addTools()
{

    cout<<endl;
    node_tool = (struct Tools*)malloc(sizeof(struct Tools));
    cout<<"Add tool number: ";
    cin>>node_tool->Tool_no;
    cout<<"Add category number: ";
    cin>>node_tool->category_no;
    cout<<"Add tool price: ";
    cin>>node_tool->price;

    node_tool->link =NULL;

    if(head1->p==NULL)
    {
        head1->p = node_tool;
    }
    else
    {
        node_tool->link = head1->p;
        head1->p = node_tool;
    }


}

void DisplayTools()
{
    struct Tools *temp;
    temp = head1->p;
    while(temp!=NULL)
    {
        cout<<"Tool Number: "<<temp->Tool_no<<endl;
        cout<<"Category Number: "<<temp->category_no<<endl;
        cout<<"price: "<<temp->price<<endl;
        temp = temp->link;
        cout<<endl;
    }
    cout<<endl;
}



void DisplayCustomers()
{
    struct Customer *temp;
    temp = head2->p;
    while(temp!=NULL)
    {
        cout<<"Customer Number: "<<temp->customer_no<<endl;
        cout<<"Tool Number: "<<temp->tool_order<<endl;
        cout<<"Category Number: "<<temp->category_order<<endl;
        cout<<"Order Month: "<<temp->order_month<<endl;
        temp = temp->link;
        cout<<endl;
    }
    cout<<endl;
}

void addFirstCustomer()
{
    cout<<endl;
    node_customer = (struct Customer*)malloc(sizeof(struct Customer));
    cout<<"Add customer number: ";
    cin>>node_customer->customer_no;
    cout<<"Add tool number: ";
    cin>>node_customer->tool_order;
    cout<<"Add category number: ";
    cin>>node_customer->category_order;
    cout<<"Add order month: ";
    cin>>node_customer->order_month;
    node_customer->link = NULL;
    head2->p = node_customer;
}
void addCustomers()
{
    cout<<endl;
    node_customer = (struct Customer*)malloc(sizeof(struct Customer));

    cout<<"Add customer number: ";
    cin>>node_customer->customer_no;
    cout<<"Add tool number: ";
    cin>>node_customer->tool_order;
    cout<<"Add category number: ";
    cin>>node_customer->category_order;
    cout<<"Add order month: ";
    cin>>node_customer->order_month;
    node_customer->link = NULL;

    struct Customer *temp;
    temp = head2->p;
    while(temp->link!=NULL)
    {
        temp = temp->link;
    }
    temp->link = node_customer;
}



void InsertStack(int orderedTool,int orderedCategory, int toolPrice, int orderMonth, int customerInfo)
{
    node_sold_tool = (struct SoldTools*)malloc(sizeof(struct SoldTools));
    node_sold_tool->Tool_no = orderedTool;
    node_sold_tool->category_no = orderedCategory;
    node_sold_tool->price = toolPrice;
    node_sold_tool->order_month = orderMonth;
    node_sold_tool->customer_info = customerInfo;
    node_sold_tool->link =NULL;

    if(head3->p==NULL)
    {
        head3->p = node_sold_tool;
    }
    else
    {
        node_sold_tool->link = head3->p;
        head3->p = node_sold_tool;
    }

}


void searchTool(int orderedTool, int orderedCategory, int orderMonth, int customerInfo)
{
    struct Tools *temp= head1->p;
    while(temp != NULL)
    {
        if((temp->Tool_no == orderedTool) && (temp->category_no == orderedCategory))
        {
            int toolPrice = temp->price;
            InsertStack(orderedTool, orderedCategory, toolPrice, orderMonth, customerInfo);
        }
        temp = temp->link;
    }

}


void Sell()
{
    struct Customer *temp ;
    temp = head2->p;
    int orderedTool = temp->tool_order;
    int orderedcategory = temp->category_order;
    int ordermonth = temp->order_month;
    int customerinfo = temp->customer_no;

    head2->p=temp->link;
    free(temp);
    searchTool(orderedTool,orderedcategory,ordermonth,customerinfo);
}


void lastSold()
{
    struct SoldTools *temp;
    temp = head3->p;
    cout<<"\nLast tool Sold"<<endl;
    cout<<"Tool Number: "<<temp->Tool_no<<endl;
    cout<<"Category Number: "<<temp->category_no<<endl;
    cout<<"Price: "<<temp->price<<endl;
    cout<<endl;
}

void report()
{
    int month, tool_count=0, total_price =0;
    cout<<"Enter the month: ";
    cin>>month;
    struct SoldTools *temp= head3->p;
    while(temp != NULL)
    {
        if(temp->order_month == month)
        {
            tool_count++;
            total_price += temp->price;
            cout<<"\nCustomer Number: "<<temp->customer_info<<endl;
            cout<<"Tool Number: "<<temp->Tool_no<<endl;
            cout<<"Category Number: "<<temp->category_no<<endl;
            cout<<"Tool Price: "<<temp->price<<endl;
        }
        temp = temp->link;
    }
    cout<<"\nTotal unit sold: "<<tool_count<<endl;
    cout<<"Total Earnings: "<<total_price<<endl;

}

int main()
{
    createHead1();
    createHead2();
    createHead3();
    int choice,totaltool,totalcus;
    while(1)
    {
        cout<<"1.Enter Tools Information "<<endl;
        cout<<"2.Enter Customer Information "<<endl;
        cout<<"3.Show Tools Information "<<endl;
        cout<<"4.Show Customer Information "<<endl;
        cout<<"5.Start selling "<<endl;
        cout<<"6.Report "<<endl;
        cout<<"-1.Exit"<<endl;
        cin>>choice;
        if(choice == 1)
        {
            cout<<"How many tools?"<<endl;
            cin>>totaltool;

            for(int i=0; i<totaltool; i++)
                addTools();

        }
        else if(choice == 2)
        {
            cout<<"How many Customers?"<<endl;
            cin>>totalcus;
            addFirstCustomer();

            for(int i=0; i<totalcus-1; i++)
                addCustomers();


        }
        else if(choice == 3)
        {
            DisplayTools();
        }
        else if(choice == 4)
        {
            DisplayCustomers();
        }
        else if(choice == 5)
        {
            for(int i=0;i<totalcus;i++)
            {
                Sell();
            }
        }
        else if(choice == 6)
        {
            lastSold();
            report();
        }
        else if(choice == -1)
        {
            break;
            return 0;
        }

    }

}
