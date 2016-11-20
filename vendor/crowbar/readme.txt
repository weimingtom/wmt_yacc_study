http://avnpc.com/pages/devlang

《自制编程语言》相关资料
日志未经声明，均为AlloVince原创。版权采用『 知识共享署名-非商业性使用 2.5 许可协议』进行许可。 Share on twitterShare on facebookShare on google_plusone_shareShare on sinaweiboShare on douban
 选择语言?▼
 自制编程语言

《自制编程语言》原书名为「プログラミング言語を作る」，从编程语言的原理讲起，手把手地带你从零开始自制编程语言：crowbar和Diksam。前者为基于语法树的无类型语言，后者为基于字节代码的静态语言。二者均具备四则运算、变量、条件转移、循环、函数说明、垃圾收集、面向对象、异常处理机制等功能。

《自制编程语言》原作者为前橋和弥，中文版由刘卓、徐谦（AlloVince）、吴雅明合译完成，北京图灵文化发展有限公司出版，现已出版。由于原版链接的资料多为作者的日语博客，考虑到本书读者大都没有日语基础，因此将《自制编程语言》资源下载以及一些相关日志翻译整理于此，希望可以帮助读者更方便的获取信息。

购买地址：

亚马逊
当当
京东
互动出版社
源代码下载
作者提供的源代码中，错误信息全部为日文，给许多读者的学习带来了一些不便。

因此译者刘卓特别翻译了代码中所有的错误信息，并提供中文版代码的打包下载。

本书所涉及到的所有源代码：

中文版源代码ZIP压缩包，最后修订时间：20131212
日文版源代码ZIP压缩包，最后修订时间：20091228
包含文件
压缩包内包含以下内容：

calc　……第2章计算器源代码
mycalc　……基于yacc/lex的计算器源代码
mycalc_ex　……基于yacc/lex的计算器扩展版源代码
llparser　……基于递归下降分析法自制计算器源代码
llparser_ex　……基于递归下降分析法自制计算器扩展版源代码
crowbar_book_0_1　……基于分析树运行的语言crowbar ver.0.1。包含基本的语句、结构控制、函数
crowbar_book_0_2　……基于分析树运行的语言crowbar ver.0.2。引入数组与GC
crowbar_book_0_3　……基于分析树运行的语言crowbar ver.0.3。内部编码采用宽字符（可支持日语）
crowbar_book_0_4　……基于分析树运行的语言crowbar ver.0.4。其他应用
diksam_book_0_1　……基于静态字节码运行的语言Diksam ver.0.1。包含基本的语句、结构控制、函数
diksam_book_0_2　……基于静态字节码运行的语言Diksam ver.0.2。引入数组
diksam_book_0_3　……基于静态字节码运行的语言Diksam ver.0.3。引入分割源代码及类
diksam_book_0_4　……基于静态字节码运行的语言Diksam ver.0.4。其他应用
编译方法
计算器的编译
Linux运行目录下的make.sh，Windows运行目录下的make.bat即可。

crowbar的编译
在文件夹中运行make（Windows下可参考书中建议，重命名为gmake）即可生成可执行文件。

Diksam的编译
对于diksam_book_0_1及diksam_book_0_2，解压后进入文件夹下的compiler目录，运行make/gmake即可。

对于diksam_book_0_3及diksam_book_0_4，解压后进入文件夹下的main目录，运行make/gmake即可。

MinGW, bison, flex安装说明
下文介绍的所有安装文件均以2013/8/23的最新版本为准。

MinGW的安装
MinGW的官方网站如下：

http://www.mingw.org/

首先进入MinGW的下载页面，会跳转到MinGW在sourceforge的项目页，Windows用户可以点击Installer，然后在列表中继续点击mingw-get-setup.exe。

MinGW MinGW

mingw-get-setup.exe并不包含实际的安装文件，而是通过网络下载MinGW的程序文件。请参考下面步骤安装：

MinGW

点击Install。

MinGW

可在Installation Directory处点击Change修改安装路径，然后点击Continue。

MinGW

MinGW会下载初始安装文件，下载完成后点击Continue。

MinGW

安装界面会切换为MinGW Installation Manager，MinGW包含了多个编译组件，选择想要安装的组件，在弹出的菜单中选择Mark for Installation。

《自制编程语言》一书中，我们只用到了make，因此只选择mingw32-base即可，当然如果磁盘空间富裕，完全可以全部选择，更加省事。

选择完毕后点击窗口菜单的Installation，选择Apply

MinGW

在弹出的确认框中点击Apply，MinGW会开始下载选择的安装包，整个下载过程视网速会占用数分钟的时间。下载完成即可以开始使用MinGW。

安装完毕后可以在安装路径下看到MinGW创建了一系列文件，其中bin目录是MinGW主要程序所在目录。例如解压crowbar的源码到c:，然后运行cmd如下编译crowbar_book_0_1（假设MinGW的安装目录为D:\MinGW）：

cd C:\win_sjis\crowbar_book_0_1
C:\win_sjis\crowbar_book_0_1>D:\MinGW\bin\mingw32-make.exe
但是每次这样运行编译指令有点麻烦，所以作者推荐复制mingw32-make.exe到同目录下，并重命名为gmake.exe。然后将D:\MinGW\bin加入系统目录。就可以直接运行：

 gmake
进行编译了。

Cygwin的安装
Cygwin是一系列自由软件的集合，可以在Windows下实现与Linux几乎一致的运行环境。

为了在Windows上实现UNIX的系统内核，Cygwin提供了名为cygwin.dll的DLL文件来模拟Linux的内核API接口及相似功能。因此Linux源代码编译都依赖cygwin.dll文件，而通过Cygwin编译的exe文件如果脱离了包含cygwin.dll的系统环境也是无法运行的。

与MinGW一样，在Cygwin中也可以安装gcc，而在《自制编程语言》一书中，作者之所以选择MinGW编译，主要是因为作者希望无论crowbar还是Diksam，都可以最终编译为一个exe文件，只需要拷入U盘就能在任意电脑运行，不受cygwin.dll的限制。

而这里介绍Cygwin的安装，是由于bison所使用的m4以及crowbar_ver.0.4所使用的“鬼车”，都依赖于Cygwin环境。

Cygwin的官方主页为：

http://www.cygwin.com/

进入主页后，可根据自己的系统环境选择下载32bit版本setup-x86.exe或64bit版本的setup-x86_64.exe。

下载后按以下方法操作（以64bit为例）

Cygwin

点击下一步

Cygwin

选择Install from Internet，点击下一步

Cygwin

在Root Directory中选择安装路径，点击下一步

Cygwin

在Local Package Directory中选择安装包的下载路径，以后卸载或重新安装时可以从安装包直接获取，无需重新下载。点击下一步

Cygwin

一般选择Direct Connection，如果网络环境特殊可根据具体情况设置代理。点击下一步

Cygwin

选择下载节点，国内一般选择163节点即可。Cygwin会首先下载所有安装包信息。

Cygwin

选择要下载的模块安装包，Cygwin已经为我们默认选择了一部分基础功能

Cygwin

这里我们为了使用bison，需要在Interpreters下勾选m4。而为了编译鬼车，需要勾选Devel下的make。

Cygwin会开始下载所有的安装包进行安装，同时在安装目录下生成Linux典型的目录结构。安装完毕后会在桌面生成Cygwin64 Terminal的快捷方式，双击之后就可以运行模拟的Linux环境了。

bison的安装
bison最新版可以在下面的页面下载：

http://gnuwin32.sourceforge.net/packages/bison.htm

一般选择Complete package, except sources一栏的下载即可，下载后为exe格式安装文件，一路next安装后即可运行。

flex的安装
flex最新版可以在下面的页面下载：

http://gnuwin32.sourceforge.net/packages/flex.htm

一般选择Complete package, except sources一栏的下载即可，下载后为exe格式安装文件，一路next安装后即可运行。

鬼车的安装
鬼车是一个正则表达式程序库，官方主页为：

http://www.geocities.jp/kosako3/oniguruma/

截至目前（2013/8/23）为止最新版本为5.9.4。进入主页后点击Latest release version 5.9.4即可下载

鬼车在Linux下的安装
鬼车默认的系统环境为Linux。在Linux下可以很简单的使用几行指令编译安装

wget http://www.geocities.jp/kosako3/oniguruma/archive/onig-5.9.4.tar.gz
tar -xvf onig-5.9.4.tar.gz
cd onig-5.9.4
./configure
make
make install
鬼车在Windows下的安装
对于Windows用户来说，我们需要借助Cygwin环境模拟Linux对其进行编译。

首先按照上文介绍的步骤安装好Cygwin，由于鬼车要求make指令名必须为make，因此首先进入MinGW的bin目录，复制mingw32-make.exe并重命名为make.exe。然后打开cmd。假设onig-5.9.4.tar.gz文件下载到C:\。运行以下指令进行解压并检查环境。

C:\>tar -xvf onig-5.9.4.tar.gz
C:\>cd onig-5.9.4
C:\onig-5.9.4>bash
bash-3.1$  ←命令提示符会切换为bash
./configure
make
理论上只要在Linux环境下，像鬼车这样基于Autoconf打包发布的软件都可以用与Linux相同的指令make install进行安装。

但是由于Windows下MinGW安装路径比较特殊，直接运行make install很可能报错。这里需要手动更新鬼车静态链接用库文件ranlib.a的索引。运行

bash-3.1$ cd .libs/
bash-3.1$ ranlib libonig.a
然后将libonig.a文件复制到MinGW安装目录下的lib文件夹内。最后运行

make install
Hoge一词的由来
在《自制编程语言》一书中，示例程序中经常使用hoge作为无意义字符串输出，而在英语程序则惯用foobar。

hoge写成日语假名是“ほげ”。那么究竟hoge是什么意思，为什么要用hoge作为无意义字符的的代表呢？作者对此进行了一系列深入细致的考证与研究。由于其中涉及到很多日本的人名、地名、风俗习惯等等，这里只选择一些中国读者比较容易理解的部分翻译整理如下。

Hoge是什么意思
Hoge是日本自古以来就口口相传的词汇，在为难、困惑、或者遇到麻烦事的时候都可以用Hoge来求救。据传Hoge一词最早的正式登场是在20世纪80年代前半，在日本各地突然同时开始流行。而使用“Hego”一词可供考证的最早记录，则是1984年曽田大明在名古屋大学所使用的某张3.5寸软盘中录入的Hoge，说不定现在还能找到呢。

注：其实上面这些看似一本正经的说明大多都是作者在恶搞而已，Hoge在日语中是一个非常口语化的词，根本无从考证。类比中文相当于要考证“我靠”一词的起源一样。而上文所说的“曽田大明”，应该是作者拿自己的某位同学在开涮吧。

什么时候使用Hoge
在为文件、函数、变量命名而苦恼时可以使用Hoge来命名。
问别人一件事的时候，如果听不懂对方的回答，那么不要重复问题，简单说一个Hoge就可以了。
有时候面对电脑不知道输入些什么，那么不妨试试输入Hoge吧
谁在使用Hoge
藤子不二雄的《哆啦A梦》：胖虎“动人”的歌唱声中必定会伴有Hoge的字眼
动画《多罗罗》的歌词中出现了Hoge
新潟县的方言中一直有Hogeru的说法
《征服C指针》Web版
请点击查看《征服C指针》Web版

声明：

原日文网页版“配列とポインタの完全制覇”与出版后的「C言語 ポインタ完全制覇」在内容上并不完全相同，这里对应截取中文简体版「C言語 ポインタ完全制覇」（《征服C指针》）的内容。前桥和弥著，吴雅明译，人民邮件出版社，2013年2月第1版。

附录：《自制编程语言》日文版页面链接
作者主页： K.Maebashi's home page
自制编程语言专题页面： 「プログラミング言語を作る」書籍情報
源代码下载页面： 「プログラミング言語を作る」ダウンロード
鬼车的安装：鬼車のインストール
Hoge一词的由来：ほげを考えるページ
《征服C指针》Web版：配列とポインタの完全制覇
 Aug24  
最新最早最热
23条评论6条新浪微博
清夜小小
清夜小小
Administrator@PC-********* ~/onig-5.9.4
$ make install
.deps/euc_jp.Plo:1: *** 多个目标匹配。 停止。
我在 鬼车在Windows下的安装 这一步执行 make install的时候报错 请教一下怎么回事啊？
3月25日回复顶转发
蓝色调和
蓝色调和
http://gnuwin32.sourceforge.net/packages/flex.htm
http://gnuwin32.sourceforge.net/packages/bison.htm
这两个网站我打不开谁能把bison和flex发到我邮箱zhwq200676@163.com 谢谢!
1月30日回复顶转发
rayment
rayment
为什么下载不了中文的源代码？
1月19日回复顶转发
bigblue
bigblue
bison下载地址http://gnuwin32.sourceforge.net/packages/bison.html 这个地址我刚试了，是不对的。应该去掉最后的l
即应为http://gnuwin32.sourceforge.net/packages/bison.htm
1月15日回复顶转发
Allo
Allo
谢谢指出，已修复
1月15日回复顶转发
郭伦标
郭伦标
老师您好；
crowbar_book_0_1编译时产生如下错误：

D:\win_sjis\crowbar_book_0_1>cmd.exe
Microsoft Windows XP [版本 5.1.2600]
(C) 版权所有 1985-2001 Microsoft Corp.

D:\win_sjis\crowbar_book_0_1>make

D:\win_sjis\crowbar_book_0_1>gmake.exe
gmake.exe: 'crowbar' is up to date.

D:\win_sjis\crowbar_book_0_1>make

D:\win_sjis\crowbar_book_0_1>gmake.exe
gcc -c -g lex.yy.c
gcc -c -g y.tab.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG main.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG interface.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG create.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG execute.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG eval.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG string.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG string_pool.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG util.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG native.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG error.c
gcc -c -g -Wall -Wswitch-enum -ansi -pedantic -DDEBUG error_message.c
cd ./memory; gmake.exe;
系统找不到指定的路径。
Makefile:23: recipe for target 'crowbar' failed
gmake.exe: *** [crowbar] Error 1

D:\win_sjis\crowbar_book_0_1>
1月12日回复顶转发
张超
张超
/usr/bin/install -c onig-config '/usr/local/bin'
test -z "/usr/local/lib" || /usr/bin/mkdir -p "/usr/local/lib"
D:/cygwin/bin/sh.exe ./libtool --mode=install /usr/bin/install -c libonig.l
a '/usr/local/lib'
libtool: install: /usr/bin/install -c .libs/libonig.lai /usr/local/lib/libonig.l
a
libtool: install: /usr/bin/install -c .libs/libonig.a /usr/local/lib/libonig.a
libtool: install: chmod 644 /usr/local/lib/libonig.a
libtool: install: ranlib /usr/local/lib/libonig.a
D:\MinGW\bin\ranlib.exe: '/usr/local/lib/libonig.a': No such file
Makefile:415: recipe for target 'install-libLTLIBRARIES' failed
make [2] : *** [install-libLTLIBRARIES] Error 1
make [2] : Leaving directory 'C:/onig-5.9.4'
Makefile:1265: recipe for target 'install-am' failed
make [1] : *** [install-am] Error 2
make [1] : Leaving directory 'C:/onig-5.9.4'
Makefile:854: recipe for target 'install-recursive' failed
make: *** [install-recursive] Error 1
2013年12月21日回复顶转发
ShiningRay
ShiningRay
第40页2.2.6 错误处理

第二段最后最好用冒号

然后第三段用引号括起来

我读了两遍才明白“下面这段文字”是什么
2013年12月20日回复顶转发
图灵乐馨
图灵乐馨
对不起，这是编辑的疏忽，我们会在重印的时候改正。“下面这段文字”指的是第3段和第4段。
1月14日回复顶转发
张超
张超
老师，您好。。。。首先按照上文介绍的步骤安装好Cygwin，由于鬼车要求make指令名必须为make，因此首先进入MinGW的bin目录，复制mingw32-make.exe并重命名为make.exe。然后打开cmd。假设onig-5.9.4.tar.gz文件下载到C:\。运行以下指令进行解压并检查环境。 ---------一，这个复制后粘贴到哪？二，是不是每个安装的软件都要设置path
2013年12月20日回复顶转发
紫夜飞星
紫夜飞星
鬼车怎么安装啊,上面说的tar什么的总提示不是可执行命令
2013年12月17日回复顶转发
洪荒
洪荒
请问，计算器实例中的 y.tab.c 和 y.tab.h 文件是如何生成的？ 执行batch脚本后，出现如下错误：
gcc: y.tab.c: No such file or directory
mycalc.l:3:19: error: y.tab.h: No such file or directory
...
2013年12月9日回复顶(1)转发
洪荒
洪荒
问题解决。 bison输出错误如下。原来bison无法处理Windows下路径包含空格的情形，重新设置安装路径后一切正常。 - 2013/12/10 2:24 PM

m4: cannot open `Files': No such file or directory
m4: cannot open `(x86)\GnuWin32\Bison/share/bison': No such file or directory
m4: cannot open `D:\Program': No such file or directory
m4: cannot open `Files': No such file or directory
m4: cannot open `(x86)\GnuWin32\Bison/share/bison/m4sugar/m4sugar.m4': No such file or directory
2013年12月10日回复顶(1)转发
Allo
Allo
感谢补充答案
2013年12月11日回复顶转发
terry
terry
老师您好；
刚买的书，看到使用yacc/lex制作计算器，没有明白整个编译的过程是什么样的？
yacc/lex编译的源文件.l和.y其中直接包含了计算器的源码了吗？是那一部分呢？yacc/lex不是把某种语言源码翻译成c语言吗？
2013年11月30日回复顶转发
Allo
Allo
你好，你的问题2.2.1节及2.2.3小节有过回答，.l文件是词法分析器规则，输出文件为词法分析器c代码
yacc同理，.y文件是语法分析器规则，输出文件为语法分析器c代码
最终通过gcc将两段c代码合并编译为一个包含词法分析器与语法分析器的可执行文件
2013年12月4日回复顶转发
wgz
wgz
您好，您可以加群126629972《自制编程语言》讨论一些相关问题吗
2013年12月15日回复顶转发
Allo
Allo
你好，如果对本书的任何翻译有疑问，可以在这里直接留言提出即可
2013年12月15日回复顶转发
洪荒
洪荒
计算器是个简化的例子，语法解析的过程就包含了运算的过程，所谓编译的结果就是运算的结果。
真正的编译器，会把计算的过程替换成中间代码生成的过程，供后端处理。
（如果说得不准确，望各位指正。）
2013年12月10日回复顶(1)转发
reading
reading
crowbar代码里面的error_message.c里面的错误提示日文能翻译一下吗
2013年11月29日回复顶转发
Allo
Allo
你好，这是一个好建议，有时间的话我们会整理一份中文提示出来。
2013年12月4日回复顶转发
Allo
Allo
中文翻译版的代码已经提供下载了
2013年12月12日回复顶转发
楼主
楼主
^_^ A老师，我先占个地。
各位读者有什么意见和建议请与我们联系哟！
2013年11月17日回复顶转发举报
社交帐号登录:

