## Markdown语法手册

[Github官方手册英文版](https://guides.github.com/features/mastering-markdown/)
[CmdMarkdown编辑器简明语法手册中文版](https://www.zybuluo.com/mdeditor?url=https%3A%2F%2Fwww.zybuluo.com%2Fstatic%2Feditor%2Fmd-help.markdown)
[前者在Github里的版本](https://github.com/gnipbao/markdown-handbook)
[公式输入语法手册完全版](https://www.zybuluo.com/codeep/note/163962)

以上都是一些比较规范的语法手册，但是GitHub的markdown解析有几个槽点：
1. 标题的#要和标题内容之间有一个空格。
2. 分点描述的数字序号比如这行前面的2. 要和内容之间有一个空格。
3. 表格的前后要有一个空行。
4. （其实是语法规范）只按回车换行的话，实际显示中会和下一行连在一起显示，所以需要显示出换行的话，请在这行最后先打两个空格再按回车；或者在行末尾直接加入<br>标签。
5. 公式太复杂会抽风，此时建议本地预览截图上传。

## C语言编程环境

我已经搭好了虚拟机，镜像文件回头放出下载。

### 使用方法：

##### 1. 下载镜像文件并解压，解压后约4.5G

##### 2. 安装VirtualBox并打开

[VirtualBox下载链接](https://download.virtualbox.org/virtualbox/5.2.22/VirtualBox-5.2.22-126460-Win.exe)

安装方法直接打开安装文件，一路下一步就可以了。
安装完之后请下载增强包以方便后续使用。下载完双击即可安装。

[增强包下载链接](https://download.virtualbox.org/virtualbox/5.2.22/Oracle_VM_VirtualBox_Extension_Pack-5.2.22.vbox-extpack)

##### 3.导入并启动虚拟机

如图所示找到注册按钮并点击
![](register.png)
找到镜像文件解压后的文件夹并打开，选择其中的SWI.vbox并打开
![](choose.png)
之后如图所示选择该虚拟机并按点击启动按钮。
![](start.png)
启动成功后，虚拟机内系统桌面上另有一份使用须知。