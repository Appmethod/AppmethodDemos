Steps to compile this demo.

1.- Open BeaconServiceDemo.groupproj
2.- Compile android service: libDownloadService.so
3.- Add android service to DownloadImage
    a) Active DownloadImage project
    b) Expand Target Platforms node
	c) Active Android platform
	d) Right click on Android platform node
	c) Click on Add Android Service... 
	e) Select DownloadService folder, click Next
	f) You have to see  libDownloadService.so, DownloadService.jar and DownloadServiceUnit.pas files. Click finish.
4.- After add the service remove DownloadServiceUnit from DownloadImage project
5.- Run DownloadImage
