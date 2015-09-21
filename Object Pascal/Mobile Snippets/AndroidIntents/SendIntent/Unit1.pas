//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

unit Unit1;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs, FMX.Controls.Presentation, FMX.StdCtrls;

type
  TForm1 = class(TForm)
    Button1: TButton;
    ToolBar1: TToolBar;
    Label1: TLabel;
    Button2: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    procedure SendTextViaIntent(const AText: string);
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.fmx}

uses Androidapi.JNI.JavaTypes, Androidapi.JNI.GraphicsContentViewText, Androidapi.Helpers, FMX.Platform.Android;

procedure TForm1.Button1Click(Sender: TObject);
begin
  SendTextViaIntent('program HelloWorld;' + sLineBreak +
    sLineBreak +
    'begin' + sLineBreak +
    '  Writeln(''Hello World'');' + sLineBreak +
    'end.' + sLineBreak);
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
   SendTextViaIntent('unit Unit1;' + sLineBreak +
    sLineBreak +
    'interface' + sLineBreak +
    sLineBreak +
    'implementation' + sLineBreak +
    sLineBreak +
    'end.' + sLineBreak);
end;

procedure TForm1.SendTextViaIntent(const AText: string);
var
  Intent: JIntent;
begin
  Intent := TJIntent.Create;
  Intent.setType(StringToJString('text/pas'));
  Intent.setAction(TJIntent.JavaClass.ACTION_VIEW);
  Intent.putExtra(TJIntent.JavaClass.EXTRA_TEXT, StringToJString(AText));
  if MainActivity.getPackageManager.queryIntentActivities(Intent, TJPackageManager.JavaClass.MATCH_DEFAULT_ONLY).size > 0 then
    MainActivity.startActivity(Intent)
  else
    ShowMessage('Receiver not found');
end;

end.
