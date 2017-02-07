VERSION 5.00
Begin VB.Form FingersPlacement 
   BackColor       =   &H00400040&
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Placement of Fingers on Keyboard"
   ClientHeight    =   6870
   ClientLeft      =   2340
   ClientTop       =   1935
   ClientWidth     =   11325
   ClipControls    =   0   'False
   Icon            =   "FingersPlacement.frx":0000
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4741.796
   ScaleMode       =   0  'User
   ScaleWidth      =   10634.76
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.Image Image1 
      Height          =   6990
      Left            =   0
      Picture         =   "FingersPlacement.frx":08CA
      Top             =   0
      Width           =   11310
   End
End
Attribute VB_Name = "FingersPlacement"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub cmdOK_Click()
Unload Me
End Sub

Private Sub Form_Unload(Cancel As Integer)
Body.Enabled = True
End Sub
