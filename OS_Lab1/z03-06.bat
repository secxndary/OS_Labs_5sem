echo off
cls
echo -- ��ப� ��ࠬ��஢: %*
echo -- ०��: %1
echo -- ��� 䠩��: %2


:: ��ࠢ�� �� ������⢨� ��ࠬ��஢
if "%1" equ "" ( 
	echo ---++ z03-06 ०�� 䠩�
	echo ---++  ०�� = {ᮧ����, 㤠����}
	echo ---++  䠩�  = ��� 䠩��
	goto EXIT
)

:: �訡�� �� ����୮� ०��� ࠡ���
if not "%1" equ "㤠����" if not "%1" equ "ᮧ����" if not "%1" equ "" (
	echo ---+ ०�� ����� �����४⭮
	goto EXIT
)

:: �訡�� �� ������⢨� 䠩�� � ०��� "㤠����"
if "%1" equ "㤠����" if not "%1" equ "" if not "%2" equ "" if not exist "%2" (
	echo ---+ 䠩� %2 �� ������
	goto EXIT
)

:: �訡�� �� ����⢮����� 䠩�� � ०��� "ᮧ����"
if "%1" equ "ᮧ����" if exist "%2" (
	echo ---+ 䠩� %2 㦥 �������
	goto EXIT
)

:: �訡�� �� ��୮� ०��� � ������⢨� ����� 䠩��
if "%1" equ "㤠����" if "%2" equ "" (
	echo ---+ �� ������ ��� 䠩��
	goto EXIT
)
if "%1" equ "ᮧ����" if "%2" equ "" (
	echo ---+ �� ������ ��� 䠩��
	goto EXIT
)



:: ��ࠡ�⪠ ��୮� ������� ᮧ����
if "%1" equ "ᮧ����" (
	copy /y NUL %2 >NUL
	echo ---+ 䠩� %2 ᮧ���
)

:: ��ࠡ�⪠ ��୮� ������� 㤠����
if "%1" equ "㤠����" (
	del "%2"
	echo ---+ 䠩� %2 㤠���
)



:EXIT
pause