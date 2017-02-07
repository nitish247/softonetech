VERSION 5.00
Begin VB.Form HelpForm 
   BackColor       =   &H00400040&
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Help"
   ClientHeight    =   5220
   ClientLeft      =   1215
   ClientTop       =   1785
   ClientWidth     =   9060
   Icon            =   "Help.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5220
   ScaleWidth      =   9060
   StartUpPosition =   1  'CenterOwner
   Begin VB.Label DescLabel 
      BackColor       =   &H8000000B&
      BackStyle       =   0  'Transparent
      Caption         =   "Hover the links for details..."
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000E&
      Height          =   1335
      Left            =   240
      TabIndex        =   7
      Top             =   3840
      Visible         =   0   'False
      Width           =   8055
   End
   Begin VB.Label Link 
      BackColor       =   &H8000000B&
      BackStyle       =   0  'Transparent
      Caption         =   "Free Type Mode"
      DataSource      =   "&H00FFFF00&"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFF00&
      Height          =   375
      Index           =   3
      Left            =   6840
      TabIndex        =   6
      Top             =   3240
      Width           =   2055
   End
   Begin VB.Label Link 
      BackColor       =   &H8000000B&
      BackStyle       =   0  'Transparent
      Caption         =   "Paragraph Mode"
      DataSource      =   "&H00FFFF00&"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFF00&
      Height          =   375
      Index           =   2
      Left            =   4320
      TabIndex        =   5
      Top             =   3240
      Width           =   2055
   End
   Begin VB.Label Link 
      BackColor       =   &H8000000B&
      BackStyle       =   0  'Transparent
      Caption         =   "Sentence Mode"
      DataSource      =   "&H00FFFF00&"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFF00&
      Height          =   375
      Index           =   1
      Left            =   2040
      TabIndex        =   4
      Top             =   3240
      Width           =   1935
   End
   Begin VB.Label Link 
      BackColor       =   &H8000000B&
      BackStyle       =   0  'Transparent
      Caption         =   "Word Mode"
      DataSource      =   "&H00FFFF00&"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   -1  'True
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFF00&
      Height          =   375
      Index           =   0
      Left            =   240
      TabIndex        =   3
      Top             =   3240
      Width           =   1455
   End
   Begin VB.Label Label3 
      BackColor       =   &H8000000B&
      BackStyle       =   0  'Transparent
      Caption         =   "Hover the following links for details..."
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000E&
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   2640
      Width           =   3615
   End
   Begin VB.Label Label2 
      BackColor       =   &H8000000B&
      BackStyle       =   0  'Transparent
      Caption         =   $"Help.frx":08CA
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000E&
      Height          =   615
      Left            =   240
      TabIndex        =   1
      Top             =   2160
      Width           =   8655
   End
   Begin VB.Label Label1 
      BackColor       =   &H8000000B&
      BackStyle       =   0  'Transparent
      Caption         =   $"Help.frx":095C
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H8000000E&
      Height          =   855
      Left            =   240
      TabIndex        =   0
      Top             =   1440
      Width           =   8655
   End
   Begin VB.Image Image1 
      Height          =   930
      Left            =   240
      Picture         =   "Help.frx":0A41
      Top             =   240
      Width           =   2580
   End
End
Attribute VB_Name = "HelpForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim FLAG As Integer, STR(0 To 3) As String

Private Sub Command1_Click()
Unload Me
End Sub


Private Sub Form_Load()
FLAG = 0
STR(0) = "In word mode, there are 100 sets, each containing 5 words which are most common in English Language. Try this at the beginning of course."
STR(1) = "In sentence mode, there are 100 sentences, most of which are English proverbs. This will be the second level of the course."
STR(2) = "In paragraph mode, there are 100 paragraphs selected from novels, information books and other web sources. After completely typing each paragraph, your typing speed and accuracy will be calculated and displayed at the right side of screen in this mode. This will be the final level of the course."
STR(3) = "In free type mode, you can copy-paste your own paragraph in main text box and can practise it, your typing speed and accuracy will be calculated and displayed at the right side of screen."
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
Dim I As Integer
If (FLAG = 1) Then
For I = 0 To 3 Step 1
Link(I).Font.Size = 10
Next I
DescLabel.Visible = False
FLAG = 0
End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
Body.Enabled = True
End Sub

Private Sub Link_MouseMove(Index As Integer, Button As Integer, Shift As Integer, X As Single, Y As Single)
Link(Index).Font.Size = 12
DescLabel.Visible = True
DescLabel.Caption = STR(Index)
FLAG = 1
End Sub
