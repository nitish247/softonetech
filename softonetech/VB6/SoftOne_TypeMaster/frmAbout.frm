VERSION 5.00
Begin VB.Form frmAbout 
   BackColor       =   &H00400040&
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "About SoftOne CafeBiz"
   ClientHeight    =   5730
   ClientLeft      =   2340
   ClientTop       =   1935
   ClientWidth     =   5550
   ClipControls    =   0   'False
   Icon            =   "frmAbout.frx":0000
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3954.948
   ScaleMode       =   0  'User
   ScaleWidth      =   5211.737
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton cmdOK 
      Cancel          =   -1  'True
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   345
      Left            =   4080
      TabIndex        =   0
      Top             =   5280
      Width           =   1260
   End
   Begin VB.Image Image2 
      Height          =   930
      Left            =   240
      Picture         =   "frmAbout.frx":08CA
      Top             =   240
      Width           =   2580
   End
   Begin VB.Label Label7 
      BackColor       =   &H00400040&
      Caption         =   "SoftOne TypeMaster"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   285
      Left            =   3000
      TabIndex        =   10
      Top             =   240
      Width           =   2445
   End
   Begin VB.Line Line1 
      X1              =   0
      X2              =   5183.565
      Y1              =   3064.567
      Y2              =   3064.567
   End
   Begin VB.Label Label6 
      BackColor       =   &H00400040&
      Caption         =   "E-mail: softonetech@yahoo.com"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   330
      Left            =   240
      TabIndex        =   9
      Top             =   4080
      Width           =   4965
   End
   Begin VB.Label Label5 
      BackColor       =   &H00400040&
      Caption         =   "Phone: +91-9028967081"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   330
      Left            =   240
      TabIndex        =   8
      Top             =   3720
      Width           =   4965
   End
   Begin VB.Line Line2 
      X1              =   0
      X2              =   5183.565
      Y1              =   2236.306
      Y2              =   2236.306
   End
   Begin VB.Label Label4 
      BackColor       =   &H00400040&
      Caption         =   "Contact for Any-time Assistance:"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   330
      Left            =   240
      TabIndex        =   7
      Top             =   3360
      Width           =   3405
   End
   Begin VB.Label Label3 
      BackColor       =   &H00400040&
      Caption         =   "SoftOne TypeMaster is a  free software tool for improvement of typing speed of a computer user. "
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   570
      Left            =   240
      TabIndex        =   6
      Top             =   2040
      Width           =   5085
   End
   Begin VB.Image Image1 
      Height          =   705
      Left            =   240
      Picture         =   "frmAbout.frx":8604
      Top             =   4560
      Width           =   2175
   End
   Begin VB.Label Label2 
      BackColor       =   &H00400040&
      Caption         =   "Version 1.0 Release Date: 1 October 2011"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   330
      Left            =   240
      TabIndex        =   5
      Top             =   2640
      Width           =   4965
   End
   Begin VB.Label Label1 
      BackColor       =   &H00400040&
      Caption         =   "An OpenSource product of SoftOne Tech, India Ltd."
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   330
      Left            =   240
      TabIndex        =   4
      Top             =   1560
      Width           =   4965
   End
   Begin VB.Label lblDescription 
      BackColor       =   &H00400040&
      Caption         =   "Typing Tutorial"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   210
      Left            =   3000
      TabIndex        =   1
      Top             =   600
      Width           =   2445
   End
   Begin VB.Label lblVersion 
      BackColor       =   &H00400040&
      Caption         =   "Version: 1.0"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   225
      Left            =   3000
      TabIndex        =   3
      Top             =   840
      Width           =   1605
   End
   Begin VB.Label lblDisclaimer 
      BackColor       =   &H00400040&
      Caption         =   "© SoftOne Tech, 2008-2011"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   345
      Left            =   240
      TabIndex        =   2
      Top             =   5400
      Width           =   2775
   End
End
Attribute VB_Name = "frmAbout"
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
