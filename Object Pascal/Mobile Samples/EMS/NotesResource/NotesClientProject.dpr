program NotesClientProject;

uses
  System.StartUpCopy,
  FMX.Forms,
  NoteTypesU in 'NoteTypesU.pas',
  NotesClientModuleU in 'NotesClientModuleU.pas' {NotesClientModule: TDataModule},
  NotesAdapterModuleU in 'NotesAdapterModuleU.pas' {NotesAdapterModule: TDataModule},
  NotesClientFormU in 'NotesClientFormU.pas' {ToDoList};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TNotesClientModule, NotesClientModule);
  Application.CreateForm(TNotesAdapterModule, NotesAdapterModule);
  //Application.CreateForm(TNotesClientForm, NotesClientForm);
  Application.CreateForm(TNotesClientForm, NotesClientForm);
  Application.Run;
end.
