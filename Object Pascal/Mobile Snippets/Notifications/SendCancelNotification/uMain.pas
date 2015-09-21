//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

unit uMain;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Dialogs, FMX.StdCtrls, FMX.Platform,
  System.Notification, FMX.Controls.Presentation;

type
  TNotificationsForm = class(TForm)
    btnSendScheduledNotification: TButton;
    ToolBar1: TToolBar;
    Label1: TLabel;
    btnSendNotificationImmediately: TButton;
    ToolBar2: TToolBar;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    NotificationC: TNotificationCenter;
    procedure btnSendScheduledNotificationClick(Sender: TObject);
    procedure btnSendNotificationImmediatelyClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  NotificationsForm: TNotificationsForm;

implementation

{$R *.fmx}
{$R *.LgXhdpiPh.fmx ANDROID}

procedure TNotificationsForm.btnSendNotificationImmediatelyClick(
  Sender: TObject);
var
  Notification: TNotification;
begin
  { verify if the service is actually supported }
  Notification := NotificationC.CreateNotification;
  try
    Notification.Name := 'MyNotification';
    Notification.AlertBody := 'Delphi for Mobile is here!';
    Notification.FireDate := Now;

    { Send notification in Notification Center }
    NotificationC.ScheduleNotification(Notification);
    { also this method is equivalent }
    // NotificationService.PresentNotification(Notification);
  finally
    Notification.DisposeOf;
  end;
end;

procedure TNotificationsForm.btnSendScheduledNotificationClick(Sender: TObject);
var
  Notification: TNotification;
begin

{ verify if the service is actually supported }
  Notification := NotificationC.CreateNotification;
  try
    Notification.Name := 'MyNotification';
    Notification.AlertBody := 'Delphi for Mobile is here!';

    { Fired in 10 second }
    Notification.FireDate := Now + EncodeTime(0,0,10,0);

    { Send notification in Notification Center }
    NotificationC.ScheduleNotification(Notification);
  finally
    Notification.DisposeOf;
  end;
end;

procedure TNotificationsForm.SpeedButton1Click(Sender: TObject);
begin
    { providing the fact that you already have a MyNotification previously issued }
  NotificationC.CancelNotification('MyNotification');
end;

procedure TNotificationsForm.SpeedButton2Click(Sender: TObject);
begin
  NotificationC.CancelAll;
end;

end.
