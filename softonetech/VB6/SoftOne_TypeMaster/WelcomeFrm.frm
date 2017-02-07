VERSION 5.00
Begin VB.Form WelcomeFrm 
   BorderStyle     =   0  'None
   Caption         =   "SoftOne TypeMaster"
   ClientHeight    =   5910
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   9210
   Icon            =   "WelcomeFrm.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5910
   ScaleWidth      =   9210
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   120
      Top             =   120
   End
   Begin VB.Image Image1 
      Height          =   6075
      Left            =   0
      Picture         =   "WelcomeFrm.frx":08CA
      Top             =   -120
      Width           =   9285
   End
End
Attribute VB_Name = "WelcomeFrm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim I As Integer

Private Sub Form_Load()
I = 0
End Sub

Private Sub Form_Unload(Cancel As Integer)
Body.Show
End Sub

Private Sub Timer1_Timer()
I = I + 1
If (I = 2) Then
Unload Me
End If
End Sub
