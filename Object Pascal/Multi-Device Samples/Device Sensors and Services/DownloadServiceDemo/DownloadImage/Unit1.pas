unit Unit1;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs, System.Notification, FMX.Objects, FMX.StdCtrls,
  FMX.Edit, FMX.Controls.Presentation;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Edit1: TEdit;
    Panel1: TPanel;
    Button1: TButton;
    Image1: TImage;
    NotificationCenter1: TNotificationCenter;
    Button2: TButton;
    procedure NotificationCenter1ReceiveLocalNotification(Sender: TObject; ANotification: TNotification);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    FFilename: string;
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.fmx}

uses
  IntentServiceUnit,
  Androidapi.Helpers;

procedure TForm1.Button1Click(Sender: TObject);
var
  LIntentService: TIntentServiceHelper;
  LURL: string;
  LFilename: string;
begin
  LURL := Edit1.Text;
  LFilename := Edit1.Text.Substring(Edit1.Text.LastIndexOf('/') +1);
  LIntentService := TIntentServiceHelper.Create('DownloadService', 0, LURL + '|' + LFilename);
  TAndroidHelper.Activity.startService(LIntentService.Intent);
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  if FFilename <> '' then
    DeleteFile(FFilename);
  Image1.Bitmap.Clear(0);
  Button2.Enabled := False;
end;

procedure TForm1.NotificationCenter1ReceiveLocalNotification(Sender: TObject; ANotification: TNotification);
begin
  TThread.Queue(nil, procedure
  begin
    FFilename := ANotification.AlertBody;
    Image1.Bitmap.LoadFromFile(FFilename);
    Button2.Enabled := True;
  end);
end;

end.
