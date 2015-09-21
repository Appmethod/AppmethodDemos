program DownloadService;

uses
  System.Android.ServiceApplication,
  DownloadServiceUnit in 'DownloadServiceUnit.pas' {DownloadServiceDM: TAndroidService},
  IntentServiceUnit in 'IntentServiceUnit.pas',
  uDownloadThread in 'uDownloadThread.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TDownloadServiceDM, DownloadServiceDM);
  Application.Run;
end.
