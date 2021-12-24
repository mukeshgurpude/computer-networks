#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
void stopwait()
{
    int surviveStatus,Frame;
    cout<<"\nEnter Frame to transmit: ";
    cin>>Frame;
    resendSNW:
    //In Internet frames lost
    cout<<"\n\n------ Some Frame Lost------ ";
    cout<<"\n--> Should this frame survive?(1/0) -> ";
    cin>>surviveStatus;
    if(surviveStatus){
        cout<<"-- Above Frames received --\n";
        cout<<"-- Acknowledgment of above frames sent by receiver --\n\n";
    }
    else{
        cout<<"-- No Frames received --\n";
        cout<<"-- No Acknowledgment of frames sent by receiver --\n\n";
        cout<<"-- After Timer Expire on sender end, frame is resend --\n";
        goto resendSNW;
    }
}
void goback(){
    int w,i,f,l,frames[50],lost_frames[50];
    cout<<"Enter window size: ";
    cin>>w;
    f = w;
    cout<<"\nEnter "<<f<<" frames: ";
    for(i=1;i<=f;i++)
        cin>>frames[i];
    cout<<"\nWith sliding window protocol the frames will be sent in the following manner\n\n";
    cout<<"After sending "<<w<<" frames at each stage sender waitsfor acknowledgement sent by the receiver\n\n";
    for(i=1;i<=f;i++)
    {
        if(i%w==0)
        {
            cout<<frames[i]<<"\n";
        }
        else
            cout<<frames[i]<<" ";
    }
    resend:
    cout<<"Enter number of frame you want to lost: ";
    cin>>l;
    if(l==0)
    {
        cout<<"\nNo frame is lost\n";
        for(i=1;i<=f;i++){
            if(i%w==0){
                cout<<frames[i]<<"\n";
                cout<<"Acknowledgement of above frames sent is received by sender\n\n";
            }
            else
                cout<<frames[i]<<" ";
        }
    }
    else{
        cout<<"Enter "<<l<<" frames: ";
        for(i=1;i<=l;i++)
            cin>>lost_frames[i];
        cout<<l<<" frames is lost so we have to send the entire window";
        cout<<"\nEntire window will be send again\n";
        for(i=1;i<=f;i++){
            if(i%w==0){
                cout<<frames[i]<<"\n";
                cout<<"Acknowledgement of above frames sent is received by sender\n\n";
            }
            else
                cout<<frames[i]<<" ";
        }
        if(f%w!=0)
        cout<<"\nAcknowledgement of above frames sent is received by sender\n";
    }
    if(l!=0)
        goto resend;
}
void selective(){
    int WindowSize,FrameCount,SentFrames[50],RecieveFrames[50];
    memset(RecieveFrames,-1,sizeof(RecieveFrames));
    //Taking Window size input
    cout<<"\n--> Enter Window Size: ";
    cin>>WindowSize;
    //Input for Frames
    cout<<"\n--> Enter "<<WindowSize<<" frames: ";
    for(int i=1;i<=WindowSize;i++)
    cin>>SentFrames[i];
    resendSNR:
    //In Internet frames lost
    cout<<"\n\n------ Some Frame Lost------ ";
    cout<<"\n--> Enter how many frame should survive: ";
    cin>>FrameCount;
    cout<<"\n--> Which Frames should survive: ";
    for(int i=1;i<=FrameCount;i++)
    cin>>RecieveFrames[i];
    cout<<"\n";
    cout<<"-- Above Frames received --\n";
    cout<<"-- Acknowledgment of above frames sent by receiver --\n\n";
    if(FrameCount<WindowSize)
    {
        int tempFrame[50];
        cout<<"--- After Getting Acknowledgment--- \n";
        for(int i=1,j=1,k=1;i<=WindowSize; i++)
        {
            if(SentFrames[i]!=RecieveFrames[k])
            {
                cout<<"\t"<<SentFrames[i];
                tempFrame[j] = SentFrames[i];
                j++;
                continue;
            }
            k++;
        }
        cout<<"\n -- Above Frames Send --";
        for(int i=0; i<50; i++)
        SentFrames[i] = tempFrame[i];
        WindowSize = WindowSize - FrameCount;
        goto resendSNR;
    }
}
int main() {
    cout<<"\n\n--- Flow Control ---\n";
    cout<<"\n 1] Stop-and-Wait ARQ";
    cout<<"\n 2] Go-Back-n ARQ";
    cout<<"\n 3] Selective repeat ARQ";
    cout<<"\n 4] Exit";
    cout<<"\n\n--> Select an option: ";
    int option1;
    cin>>option1;
    switch(option1)
    {
        case 1:
          stopwait();
          break;
        case 2:
          goback();
          break;
        case 3:
          selective();
          break;
        case 4:
          break;
          return 0;
        default:
            cout<<"\n\nInvalid Option\n\n";
    }
    return 0;
}
