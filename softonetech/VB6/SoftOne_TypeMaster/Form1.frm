VERSION 5.00
Object = "{3B7C8863-D78F-101B-B9B5-04021C009402}#1.2#0"; "RICHTX32.OCX"
Begin VB.Form Body 
   BackColor       =   &H00000000&
   Caption         =   "SoftOne TypeMaster"
   ClientHeight    =   10290
   ClientLeft      =   165
   ClientTop       =   555
   ClientWidth     =   15240
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   Picture         =   "Form1.frx":08CA
   ScaleHeight     =   10290
   ScaleWidth      =   15240
   WindowState     =   2  'Maximized
   Begin VB.Timer Timer2 
      Enabled         =   0   'False
      Interval        =   1000
      Left            =   480
      Top             =   0
   End
   Begin VB.CommandButton GoBut 
      Caption         =   "Go"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   8400
      TabIndex        =   40
      Top             =   5280
      Width           =   855
   End
   Begin VB.TextBox SID 
      Alignment       =   1  'Right Justify
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   178
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   6720
      TabIndex        =   39
      Text            =   "1"
      Top             =   5280
      Width           =   615
   End
   Begin VB.CommandButton NextBut 
      Caption         =   "Next >>"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   10200
      TabIndex        =   3
      Top             =   5280
      Width           =   1695
   End
   Begin VB.CommandButton PrevBut 
      Caption         =   "<< Previous"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3360
      TabIndex        =   2
      Top             =   5280
      Width           =   1815
   End
   Begin RichTextLib.RichTextBox TB1 
      Height          =   1815
      Left            =   3360
      TabIndex        =   4
      Tag             =   "1"
      Top             =   960
      Width           =   8535
      _ExtentX        =   15055
      _ExtentY        =   3201
      _Version        =   393217
      ReadOnly        =   -1  'True
      ScrollBars      =   2
      TextRTF         =   $"Form1.frx":30F5D
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "Arial Narrow"
         Size            =   21.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   400
      Left            =   0
      Top             =   0
   End
   Begin RichTextLib.RichTextBox TB2 
      Height          =   1815
      Left            =   3360
      TabIndex        =   1
      Top             =   3240
      Width           =   8535
      _ExtentX        =   15055
      _ExtentY        =   3201
      _Version        =   393217
      TextRTF         =   $"Form1.frx":30FE8
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "Arial Narrow"
         Size            =   21.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
   End
   Begin VB.Label Label7 
      BackStyle       =   0  'Transparent
      Caption         =   "Right Hand"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   12840
      TabIndex        =   50
      Top             =   5760
      Width           =   1575
   End
   Begin VB.Label Label6 
      BackStyle       =   0  'Transparent
      Caption         =   "Left Hand"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   960
      TabIndex        =   49
      Top             =   5760
      Width           =   1575
   End
   Begin VB.Label Label5 
      BackStyle       =   0  'Transparent
      Caption         =   "/100"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   7440
      TabIndex        =   48
      Top             =   5280
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   """"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   255
      Index           =   1
      Left            =   13080
      TabIndex        =   47
      Top             =   7440
      Width           =   135
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   ":"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   255
      Index           =   0
      Left            =   12120
      TabIndex        =   46
      Top             =   7320
      Width           =   135
   End
   Begin VB.Image Image1 
      Height          =   930
      Left            =   360
      Picture         =   "Form1.frx":3106B
      Top             =   480
      Width           =   2580
   End
   Begin VB.Label ModeName 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "ModeName"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000008&
      Height          =   375
      Left            =   6480
      TabIndex        =   45
      Top             =   360
      Width           =   2655
   End
   Begin VB.Label Label3 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Result"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000008&
      Height          =   735
      Left            =   12240
      TabIndex        =   44
      Top             =   1440
      Visible         =   0   'False
      Width           =   2895
   End
   Begin VB.Label Label2 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Accuracy: "
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000008&
      Height          =   375
      Left            =   12240
      TabIndex        =   43
      Top             =   1080
      Visible         =   0   'False
      Width           =   2895
   End
   Begin VB.Label Label1 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Speed: "
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000008&
      Height          =   615
      Left            =   12240
      TabIndex        =   42
      Top             =   480
      Visible         =   0   'False
      Width           =   2895
   End
   Begin VB.Label Label4 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Last Paragraph Details:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000008&
      Height          =   375
      Left            =   12240
      TabIndex        =   41
      Top             =   120
      Visible         =   0   'False
      Width           =   2895
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "?"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   255
      Index           =   64
      Left            =   12600
      TabIndex        =   38
      Top             =   8520
      Width           =   255
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      BorderStyle     =   0  'Transparent
      Height          =   735
      Index           =   64
      Left            =   12240
      Top             =   8280
      Width           =   735
   End
   Begin VB.Line Line1 
      X1              =   3240
      X2              =   12000
      Y1              =   3000
      Y2              =   3000
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   1455
      Index           =   1
      Left            =   480
      Top             =   3840
      Width           =   375
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   2415
      Index           =   2
      Left            =   960
      Top             =   2880
      Width           =   375
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   2895
      Index           =   3
      Left            =   1440
      Top             =   2400
      Width           =   375
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   2415
      Index           =   4
      Left            =   1920
      Top             =   2880
      Width           =   375
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   1215
      Index           =   5
      Left            =   2400
      Top             =   4080
      Width           =   375
   End
   Begin VB.Shape Shape3 
      BackColor       =   &H00400000&
      BackStyle       =   1  'Opaque
      BorderColor     =   &H00C0C0C0&
      BorderStyle     =   0  'Transparent
      FillColor       =   &H00C0C0C0&
      Height          =   3495
      Left            =   360
      Top             =   2160
      Width           =   2655
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   1575
      Index           =   6
      Left            =   14280
      Top             =   3720
      Width           =   375
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   2535
      Index           =   7
      Left            =   13800
      Top             =   2760
      Width           =   375
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   3015
      Index           =   8
      Left            =   13320
      Top             =   2280
      Width           =   375
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   2535
      Index           =   9
      Left            =   12840
      Top             =   2760
      Width           =   375
   End
   Begin VB.Shape Finger 
      BackColor       =   &H00C0E0FF&
      BackStyle       =   1  'Opaque
      Height          =   1215
      Index           =   10
      Left            =   12360
      Top             =   4080
      Width           =   375
   End
   Begin VB.Shape Shape2 
      BackColor       =   &H00400000&
      BackStyle       =   1  'Opaque
      BorderColor     =   &H00C0C0C0&
      BorderStyle     =   0  'Transparent
      FillColor       =   &H00C0C0C0&
      Height          =   3615
      Left            =   12240
      Top             =   2040
      Width           =   2655
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Backspace"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   375
      Index           =   55
      Left            =   12840
      TabIndex        =   37
      Top             =   6480
      Width           =   1575
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   55
      Left            =   12600
      Top             =   6360
      Width           =   2175
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "."
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   255
      Index           =   63
      Left            =   11760
      TabIndex        =   36
      Top             =   8520
      Width           =   255
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "'"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   255
      Index           =   62
      Left            =   10680
      TabIndex        =   35
      Top             =   8640
      Width           =   255
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   ";"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   255
      Index           =   60
      Left            =   12120
      TabIndex        =   34
      Top             =   7680
      Width           =   135
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "'"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   255
      Index           =   61
      Left            =   13080
      TabIndex        =   33
      Top             =   7800
      Width           =   255
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   61
      Left            =   12840
      Top             =   7320
      Width           =   735
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   59
      Left            =   5160
      Top             =   9240
      Width           =   5175
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Tab"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   375
      Index           =   56
      Left            =   1800
      TabIndex        =   32
      Top             =   6480
      Width           =   615
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   56
      Left            =   1440
      Top             =   6360
      Width           =   1335
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Caps Lock"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   14.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   375
      Index           =   57
      Left            =   1560
      TabIndex        =   31
      Top             =   7440
      Width           =   1575
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   57
      Left            =   1440
      Top             =   7320
      Width           =   1575
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Shift"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   375
      Index           =   58
      Left            =   2160
      TabIndex        =   30
      Top             =   8400
      Width           =   855
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   58
      Left            =   1440
      Top             =   8280
      Width           =   1935
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      BorderStyle     =   0  'Transparent
      Height          =   735
      Index           =   63
      Left            =   11280
      Top             =   8280
      Width           =   735
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   62
      Left            =   10320
      Top             =   8280
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "M"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   77
      Left            =   9600
      TabIndex        =   29
      Top             =   8400
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   77
      Left            =   9360
      Top             =   8280
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "N"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   78
      Left            =   8640
      TabIndex        =   28
      Top             =   8400
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   78
      Left            =   8400
      Top             =   8280
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "B"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   66
      Left            =   7680
      TabIndex        =   27
      Top             =   8400
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   66
      Left            =   7440
      Top             =   8280
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "V"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   86
      Left            =   6720
      TabIndex        =   26
      Top             =   8400
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   86
      Left            =   6480
      Top             =   8280
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "C"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   67
      Left            =   5760
      TabIndex        =   25
      Top             =   8400
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   67
      Left            =   5520
      Top             =   8280
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "X"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   88
      Left            =   4800
      TabIndex        =   24
      Top             =   8400
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   88
      Left            =   4560
      Top             =   8280
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Z"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   90
      Left            =   3840
      TabIndex        =   23
      Top             =   8400
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   90
      Left            =   3600
      Top             =   8280
      Width           =   735
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   60
      Left            =   11880
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "L"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   76
      Left            =   11160
      TabIndex        =   22
      Top             =   7440
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   76
      Left            =   10920
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "K"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   75
      Left            =   10200
      TabIndex        =   21
      Top             =   7440
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   75
      Left            =   9960
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "J"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   74
      Left            =   9240
      TabIndex        =   20
      Top             =   7440
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   74
      Left            =   9000
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "H"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   72
      Left            =   8280
      TabIndex        =   19
      Top             =   7440
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   72
      Left            =   8040
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "G"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   71
      Left            =   7320
      TabIndex        =   18
      Top             =   7440
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   71
      Left            =   7080
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "F"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   70
      Left            =   6360
      TabIndex        =   17
      Top             =   7440
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   70
      Left            =   6120
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "D"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   68
      Left            =   5400
      TabIndex        =   16
      Top             =   7440
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   68
      Left            =   5160
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "S"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   83
      Left            =   4440
      TabIndex        =   15
      Top             =   7440
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   83
      Left            =   4200
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "A"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   65
      Left            =   3480
      TabIndex        =   14
      Top             =   7440
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   65
      Left            =   3240
      Top             =   7320
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "P"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   80
      Left            =   11880
      TabIndex        =   13
      Top             =   6480
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   80
      Left            =   11640
      Top             =   6360
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "O"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   79
      Left            =   10920
      TabIndex        =   12
      Top             =   6480
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   79
      Left            =   10680
      Top             =   6360
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "I"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   73
      Left            =   9960
      TabIndex        =   11
      Top             =   6480
      Width           =   255
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   73
      Left            =   9720
      Top             =   6360
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "U"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   85
      Left            =   9000
      TabIndex        =   10
      Top             =   6480
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   85
      Left            =   8760
      Top             =   6360
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Y"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   89
      Left            =   8040
      TabIndex        =   9
      Top             =   6480
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   89
      Left            =   7800
      Top             =   6360
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "T"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   84
      Left            =   7080
      TabIndex        =   8
      Top             =   6480
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   84
      Left            =   6840
      Top             =   6360
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "R"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   82
      Left            =   6120
      TabIndex        =   7
      Top             =   6480
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   82
      Left            =   5880
      Top             =   6360
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "E"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   69
      Left            =   5160
      TabIndex        =   6
      Top             =   6480
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   69
      Left            =   4920
      Top             =   6360
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "W"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   87
      Left            =   4200
      TabIndex        =   5
      Top             =   6480
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   87
      Left            =   3960
      Top             =   6360
      Width           =   735
   End
   Begin VB.Label Letter 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Q"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000004&
      Height          =   495
      Index           =   81
      Left            =   3240
      TabIndex        =   0
      Top             =   6480
      Width           =   375
   End
   Begin VB.Shape Box 
      BackColor       =   &H00000000&
      BackStyle       =   1  'Opaque
      Height          =   735
      Index           =   81
      Left            =   3000
      Top             =   6360
      Width           =   735
   End
   Begin VB.Menu Mode 
      Caption         =   "&Mode"
      Begin VB.Menu Words 
         Caption         =   "&Words"
         Checked         =   -1  'True
         Shortcut        =   ^W
      End
      Begin VB.Menu Sentence 
         Caption         =   "&Sentence"
         Shortcut        =   ^S
      End
      Begin VB.Menu Paragraph 
         Caption         =   "&Paragraph"
         Shortcut        =   ^P
      End
      Begin VB.Menu Free 
         Caption         =   "&Free Type"
         Shortcut        =   ^F
      End
   End
   Begin VB.Menu Help 
      Caption         =   "&Help"
      Begin VB.Menu General 
         Caption         =   "&General Help"
         Shortcut        =   {F1}
      End
      Begin VB.Menu Placement 
         Caption         =   "Placement of Fingers on Keyboard"
         Shortcut        =   {F2}
      End
      Begin VB.Menu About 
         Caption         =   "&About SoftOne TypeMaster"
      End
   End
   Begin VB.Menu Quit 
      Caption         =   "&Quit"
   End
End
Attribute VB_Name = "Body"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim BLINK As Boolean, BLNKID As Boolean, BLNKID1 As Boolean
Dim FINID As Integer
Dim STREAM As String
Dim WORD(1 To 100, 1 To 3) As String
Dim FINGERS(1 To 10, 1 To 7) As Integer
Dim KEY As Integer, SECOND As Integer, ERRCNT As Integer
Dim BCHAR As Integer, BLEFT As Integer, BRIGHT As Integer
Dim SHIFTPASS As Boolean
Dim MODEINDEX As Integer, STRID As Integer

Function CHANGESEN() As Integer
Dim X As Integer, CHR As String
ERRCNT = 0
TB1.Text = WORD(STRID, MODEINDEX)
TB2.Text = ""
SID.Text = CStr(STRID)

TB1.SelStart = 1
TB1.SelLength = Len(TB1.Text)
TB1.SelColor = RGB(0, 0, 0)

TB1.SelStart = 0
TB1.SelLength = 1
CHR = TB1.SelText

KEY = Asc(CHR)

If (KEY >= 65 And KEY <= 90) Then
SHIFTPASS = True
Else
If (KEY >= 97 And KEY <= 122) Then
KEY = KEY - 32
Else
If (KEY = 32) Then
KEY = 59
Else
If (KEY = 44) Then
KEY = 62
Else
If (KEY = 46) Then
KEY = 63
Else
If (KEY = 58 Or KEY = 59) Then
    KEY = 60
    If (KEY = 59) Then
        SHIFTPASS = True
    End If
Else
If (KEY = 34 Or KEY = 39) Then
    KEY = 61
    If (KEY = 39) Then
        SHIFTPASS = True
    End If
Else
If (KEY = 64) Then
        SHIFTPASS = True
    KEY = 63
Else
    KEY = 0
End If
End If
End If
End If
End If
End If
End If
End If

TB2.SetFocus
End Function

Private Sub Command1_Click()

End Sub

Function STOPBLINK()
Timer1.Enabled = False
X = 55
While (X <= 90)
If (Box(X).BackColor = &HFF00&) Then
Box(X).BackColor = &H0&
End If
X = X + 1
Wend
X = 1
While (X <= 10)
If (Finger(X).BackColor = &HFF00&) Then
Finger(X).BackColor = &HC0E0FF
End If
X = X + 1
Wend
End Function

Function COUNTSPEED() As Integer
Dim REFSTR As String, WORDCOUNT As Integer, TEMP As String, i As Integer, Speed As Integer, ACCURACY As Integer
On Error Resume Next
REFSTR = TB2.Text
i = 1
WORDCOUNT = 0
CHARCOUNT = 0
Speed = 0
While (i <= Len(REFSTR))
    TEMP = Mid$(REFSTR, i, 1)
    If (Asc(TEMP) = 32) Then
        WORDCOUNT = WORDCOUNT + 1
    End If
    i = i + 1
Wend
WORDCOUNT = WORDCOUNT + 1
ACCURACY = 100 - (ERRCNT / i) * 100
Speed = WORDCOUNT / SECOND * 60
Label1.Caption = "Speed: " + CStr(Speed) + " Words per Minute"
Label2.Caption = "Accuracy: " + CStr(ACCURACY) + "%"
If (Speed <= 10) Then
Label3.Caption = "Poor! Need More Practice!"
Else
If (Speed >= 11 And Speed <= 20) Then
Label3.Caption = "Not Bad! Need Practice!"
Else
If (Speed >= 21 And Speed <= 30) Then
Label3.Caption = "Good! Carry It On!"
Else
If (Speed >= 31 And Speed <= 40) Then
Label3.Caption = "Very Good! Keep It Up!"
Else
If (Speed >= 41 And Speed <= 49) Then
Label3.Caption = "Excellent!"
Else
If (Speed >= 50) Then
Label3.Caption = "You are the awesome TypeMaster!"
End If
End If
End If
End If
End If
End If
SECOND = 0
Timer2.Enabled = False
End Function

Private Sub About_Click()
Body.Enabled = False
frmAbout.Show
End Sub

Private Sub Form_Load()
Timer1.Enabled = True
BLINK = True
BLNKID = True
BLNKID1 = True
BCHAR = 0
BLEFT = 0
BRIGHT = 0
SECOND = 0
ERRCNT = 0
SHIFTPASS = False
ModeName.Caption = "Word Mode"

FINGERS(1, 1) = Asc("Q")
FINGERS(1, 2) = Asc("A")
FINGERS(1, 3) = Asc("Z")
FINGERS(1, 4) = 0
FINGERS(1, 5) = 0
FINGERS(1, 6) = 0
FINGERS(1, 7) = 0

FINGERS(2, 1) = Asc("W")
FINGERS(2, 2) = Asc("S")
FINGERS(2, 3) = 0
FINGERS(2, 4) = 0
FINGERS(2, 5) = 0
FINGERS(2, 6) = 0
FINGERS(2, 7) = 0

FINGERS(3, 1) = Asc("E")
FINGERS(3, 2) = Asc("D")
FINGERS(3, 3) = Asc("X")
FINGERS(3, 4) = 0
FINGERS(3, 5) = 0
FINGERS(3, 6) = 0
FINGERS(3, 7) = 0

FINGERS(4, 1) = Asc("F")
FINGERS(4, 2) = Asc("G")
FINGERS(4, 3) = Asc("R")
FINGERS(4, 4) = Asc("T")
FINGERS(4, 5) = Asc("C")
FINGERS(4, 6) = Asc("V")
FINGERS(4, 7) = Asc("B")

FINGERS(5, 1) = 59
FINGERS(5, 2) = 0
FINGERS(5, 3) = 0
FINGERS(5, 4) = 0
FINGERS(5, 5) = 0
FINGERS(5, 6) = 0
FINGERS(5, 7) = 0

FINGERS(6, 1) = 60
FINGERS(6, 2) = 63
FINGERS(6, 3) = Asc("P")
FINGERS(6, 4) = 55
FINGERS(6, 5) = 60
FINGERS(6, 6) = 61
FINGERS(6, 7) = 63

FINGERS(7, 1) = Asc("O")
FINGERS(7, 2) = Asc("L")
FINGERS(7, 3) = 62
FINGERS(7, 4) = 0
FINGERS(7, 5) = 0
FINGERS(7, 6) = 0
FINGERS(7, 7) = 0

FINGERS(8, 1) = Asc("I")
FINGERS(8, 2) = Asc("K")
FINGERS(8, 3) = 0
FINGERS(8, 4) = 0
FINGERS(8, 5) = 0
FINGERS(8, 6) = 0
FINGERS(8, 7) = 0

FINGERS(9, 1) = Asc("J")
FINGERS(9, 2) = Asc("H")
FINGERS(9, 3) = Asc("N")
FINGERS(9, 4) = Asc("U")
FINGERS(9, 5) = Asc("Y")
FINGERS(9, 6) = Asc("M")
FINGERS(9, 7) = 0

WORD(1, 1) = "aaa bbb ccc ddd eee"
WORD(2, 1) = "fff ggg hhh iii jjj kkk"
WORD(3, 1) = "lll mmm nnn ooo ppp"
WORD(4, 1) = "qqq rrr sss ttt uuu vvv"
WORD(5, 1) = "www xxx yyy zzz"
WORD(6, 1) = "abc def ghi jkl mno "
WORD(7, 1) = "pqrs tuv wxyz"
WORD(8, 1) = "about after again along also"
WORD(9, 1) = "because before between below better"
WORD(10, 1) = "certain change children country computer"
WORD(11, 1) = "don't during different download development"
WORD(12, 1) = "each example email enough everybody"
WORD(13, 1) = "font fever friend finally facebook"
WORD(14, 1) = "group given google getting government"
WORD(15, 1) = "happy heading heart hundred however"
WORD(16, 1) = "idea itself internet important information"
WORD(17, 1) = "just joined journalist justify joystick"
WORD(18, 1) = "keeper kernel kingdom keyboard knowledge"
WORD(19, 1) = "love laugh letter language laboratory"
WORD(20, 1) = "main mouse measure message mechanical"
WORD(21, 1) = "name never north national nutrition"
WORD(22, 1) = "open object oxygen overall operation"
WORD(23, 1) = "paint pencil potter physical percentage"
WORD(24, 1) = "quiz queen queue quality quotient"
WORD(25, 1) = "race radio refresh robotics refrigerator"
WORD(26, 1) = "say server status software spectacular"
WORD(27, 1) = "table textual transition threshold technology"
WORD(28, 1) = "undo upload ultimate unicorn ultrasonic"
WORD(29, 1) = "virus vacuum volume various virtual"
WORD(30, 1) = "wave weight world without windows"
WORD(31, 1) = "x-mas x-ray xenon xerox xylophone"
WORD(32, 1) = "you yeild yellow yahoo youngster"
WORD(33, 1) = "zoo zero zone zigzag zodiac"
WORD(34, 1) = "marking sudden unnecessary digital integrity"
WORD(35, 1) = "hospitality inherent thumb countless flame"
WORD(36, 1) = "accurate fantastic obstruction unconditionally insistence"
WORD(37, 1) = "falter trouble reactor conscience intuition"
WORD(38, 1) = "trespass supernatural terrorist exaggeration excessive"
WORD(39, 1) = "mornization preference premium appreciation chickenpox"
WORD(40, 1) = "instructor unauthorized precious inattention ignorant"
WORD(41, 1) = "sequence proporional empirical deducible attachment"
WORD(42, 1) = "connection scheduled involuntary investigation accidental"
WORD(43, 1) = "corruption insulted unsuccessful infinite unfamiliar"
WORD(44, 1) = "solidarity concentration together agreement harmony"
WORD(45, 1) = "disgusting brilliance burden attraction unhealed"
WORD(46, 1) = "traverse acquaintance desolate pharmacology propriety"
WORD(47, 1) = "rubbish boring dagger severe thunder compassion"
WORD(48, 1) = "contract compatibility imaginary possession feebleness"
WORD(49, 1) = "resolution euphonious inclination embrace penny"
WORD(50, 1) = "laborious distressed excercise gymnastic document"
WORD(51, 1) = "suocation surround memorize circumference inconvinient"
WORD(52, 1) = "weapon terminator boundary announcement confusion"
WORD(53, 1) = "gossip astonish ascent addiction eyeglasses"
WORD(54, 1) = "movement inflation character cleverness savour"
WORD(55, 1) = "continuous commence indecent spectacles stickiness"
WORD(56, 1) = "avoidance circumstance limestone magnetic slander"
WORD(57, 1) = "glimpse trumpeting crunch destroy sorcerer"
WORD(58, 1) = "vigorous crossword commission watchman deviation"
WORD(59, 1) = "patronage fearless jingle pleasant comfortable"
WORD(60, 1) = "smashing analysis impression reflection sprikling"
WORD(61, 1) = "provoke octroi injury globally heaven"
WORD(62, 1) = "monstrous generator preservation encourage intestinal"
WORD(63, 1) = "reproduction mandate inherent seizure statement"
WORD(64, 1) = "responsibility assumption discharge gathering community"
WORD(65, 1) = "acclaim preparation swimming aqueous imperative"
WORD(66, 1) = "waterproof reservoir practically jewellery poisonous"
WORD(67, 1) = "somehow cautious globalisation radical vacancy"
WORD(68, 1) = "awareness treatment suppress mosquito magically"
WORD(69, 1) = "adult determination gymnasium animation creature"
WORD(70, 1) = "desperate lifetime biography lifestyle antiquated"
WORD(71, 1) = "exhaust victory championship harmony entertainment"
WORD(72, 1) = "negligible hazardous cultivation dynamism emphatic"
WORD(73, 1) = "combustible turbulent obsession woodland sexy"
WORD(74, 1) = "spring criticise slumber typewriter collision"
WORD(75, 1) = "milestone phase cheese territory suspension"
WORD(76, 1) = "evasive troublesome pinpoint annotation sugercane"
WORD(77, 1) = "beautiful survival against piercing extreme"
WORD(78, 1) = "grasshopper prominence assertive category"
WORD(79, 1) = "solid crush stupid treasure wholesale"
WORD(80, 1) = "maintenance detain hexadecimal refractory understand"
WORD(81, 1) = "omniscience dermatologist amusing shivering cease"
WORD(82, 1) = "directly shelter fabrication disturbance idiot"
WORD(83, 1) = "destiny robot resession sorry annually"
WORD(84, 1) = "southbound antarctic demonstration offering"
WORD(85, 1) = "ornaments courtesy married dazzling frank"
WORD(86, 1) = "poseless initiation rectifier obstinate telescope"
WORD(87, 1) = "ambassador television illustration hesitation needle"
WORD(88, 1) = "express ambiguous daring struggle threatning"
WORD(89, 1) = "earthquake microprocessor metallurgy breathless stream"
WORD(90, 1) = "unexpected current energy cloud thanks"
WORD(91, 1) = "pomegranate oscillate plague connive visualise"
WORD(92, 1) = "resource acrobat conspicuous drumming affectation"
WORD(93, 1) = "grievance shining restlessness arrangement galaxy"
WORD(94, 1) = "immediately principle willingly youngster absorbed"
WORD(95, 1) = "glowing brilliant powerful separation adjustment"
WORD(96, 1) = "strain philosophical temporarily thermodynamics protector"
WORD(97, 1) = "telegraph optical hatefully intensly fragment"
WORD(98, 1) = "capability hurricane astringent comparative abrupt"
WORD(99, 1) = "scuttle satisfied fluctuation radiance inadequate"
WORD(100, 1) = "splender stammering abandoned resignation triad"


'All the SENTENCE drills are stored here...
WORD(1, 2) = "Quick brown fox jumps over the lazy dog."
WORD(2, 2) = "Chase the excellence, success will follow."
WORD(3, 2) = "Ability can take you to the top, but it takes character to keep you there."
WORD(4, 2) = "Absence makes the heart grow fonder but makes the mind forget."
WORD(5, 2) = "All the world is your country, to do good is your religion."
WORD(6, 2) = "An expert is the one who knows more and more about less and less."
WORD(7, 2) = "A bad settlement is better than a good lawsuit."
WORD(8, 2) = "Before criticizing a man, walk a mile in his shoes."
WORD(9, 2) = "Better to have it and not need it than to need it and not have it."
WORD(10, 2) = "A blow with a word strikes deeper than a blow with a sword."
WORD(11, 2) = "A candle that burns twice as bright burns half as long"
WORD(12, 2) = "A coward dies a thousand times before his death. The valiant never taste of death but once."
WORD(13, 2) = "Desperate times call for desperate measures."
WORD(14, 2) = "Don't judge a man by the size of his hat, but by the angle of his tilt."
WORD(15, 2) = "A drop of knowledge is greater than an ocean of strength."
WORD(16, 2) = "A dull pencil is greater than the sharpest memory."
WORD(17, 2) = "The early bird catches the worm. But the second mouse gets the cheese."
WORD(18, 2) = "Education is a progressive discovering of our own ignorance."
WORD(19, 2) = "Education makes machines which act like men and produces men who act like machines."
WORD(20, 2) = "Effort is important, but knowing where to make an effort makes all the difference."
WORD(21, 2) = "Even the best perfumes of the world lose their fragrance when you are not around me."
WORD(22, 2) = "Everyone talks of changing the world, but no one talks of changing himself."
WORD(23, 2) = "Everyone wants to go to heaven, but no one wants to die."
WORD(24, 2) = "Everything good in life is either illegal, immoral, or fattening."
WORD(25, 2) = "Fifty percent of something is better than one hundred percent of nothing."
WORD(26, 2) = "From those to whom much is given, much is expected."
WORD(27, 2) = "Give a man a fish and you feed him for a day; teach a man to fish and you feed him for a lifetime."
WORD(28, 2) = "Great spirits have always encountered violent opposition from mediocre minds."
WORD(29, 2) = "A good surgeon has an eagle's eye, a lion's heart, and a lady's hand."
WORD(30, 2) = "The head and feet keep warm, the rest will take no harm."
WORD(31, 2) = "I complained I had no shoes until I met a man who had no feet."
WORD(32, 2) = "I have the whole world against me, I show my back and the whole world is following me."
WORD(33, 2) = "If God had wanted man to fly, he would have given him wings."
WORD(34, 2) = "If you believe that dreams can come true be prepared for the occasional nightmare."
WORD(35, 2) = "If you don't know where you're going, any train will get you there."
WORD(36, 2) = "If you love somebody, let them go, for if they return, they were always yours. And if they don't, they never were."
WORD(37, 2) = "It is through the small things we do that we learn, not the big things"
WORD(38, 2) = "In the mind of thieves the moon is always shining."
WORD(39, 2) = "A journey of a thousand miles starts with a single step."
WORD(40, 2) = "Keep your friends close, but your enemies closer"
WORD(41, 2) = "Kindness, like a boomerang, always returns"
WORD(42, 2) = "Laughter is the best medicine for them who do not know how to laugh."
WORD(43, 2) = "A lie can be halfway around the world before the truth gets its boots on."
WORD(44, 2) = "Life is ten percent what happens to you and ninety percent how you respond to it."
WORD(45, 2) = "Little enemies and little wounds must not be despised."
WORD(46, 2) = "Love is not finding someone to live with; it's finding someone whom you can't live without."
WORD(47, 2) = "Mirrors do everything we do, but they cannot think for themselves."
WORD(48, 2) = "The more you know, the more you know you don't know."
WORD(49, 2) = "Money can't buy everything, but everything needs money"
WORD(50, 2) = "A man is known by the company he keeps."
WORD(51, 2) = "The nail that sticks up will be hammered down."
WORD(52, 2) = "Nature, time, and patience are three great physicians."
WORD(53, 2) = "Never let the right hand know what the left hand is doing."
WORD(54, 2) = "One man's terrorist is another man's freedom fighter."
WORD(55, 2) = "Once in a lifetime comes often, so be prepared."
WORD(56, 2) = "Opportunity is waiting, you need but to open the door."
WORD(57, 2) = "Our greatest glory is not in never falling but in rising every time we fall."
WORD(58, 2) = "The pain of the little finger is felt by the entire body."
WORD(59, 2) = "Proverbs are long life experiences, told in one short sentence."
WORD(60, 2) = "The rotten apple injures its neighbors."
WORD(61, 2) = "Someone who gossips to you will gossip about you."
WORD(62, 2) = "Success grows out of struggles to overcome difficulties."
WORD(63, 2) = "Straightn not the dog's tail even in the bamboo hollow."
WORD(64, 2) = "The teacher has not taught, until the student has learned."
WORD(65, 2) = "There are so many things to say that are better left unsaid."
WORD(66, 2) = "There are three types of lies - lies, damned lies, and statistics."
WORD(67, 2) = "Thinking the worst always prepares you for the worst."
WORD(68, 2) = "Try not to become a man of success but a man of value."
WORD(69, 2) = "Those who live in glass houses shouldn't throw stones."
WORD(70, 2) = "To know the road ahead ask those coming back."
WORD(71, 2) = "An unasked question is the most futile thing in the world"
WORD(72, 2) = "Unprepare to prepare, be prepared to be unprepared"
WORD(73, 2) = "Use it up, wear it out, make do with, or do without"
WORD(74, 2) = "The value is determined by the agreement of two people."
WORD(75, 2) = "Vision without action is a daydream. Action without vision is a nightmare."
WORD(76, 2) = "We can't always build the future for our youth, but we can build our youth for the future."
WORD(77, 2) = "We ourselves feel that what we are doing is just a drop in the ocean, but the ocean would be less without that drop."
WORD(78, 2) = "What a tangled web we weave, when first we practice to deceive."
WORD(79, 2) = "Words uttered only causes confusion. Words written only causes history."
WORD(80, 2) = "The worst way to miss someone is to be sitting right beside them knowing you can't have them."
WORD(81, 2) = "Write injuries in the sand, kindnesses in marble."
WORD(82, 2) = "You always admire what you really dont understand."
WORD(83, 2) = "You always find something in the last place you look."
WORD(84, 2) = "You can lead a horse to water but you can't make it drink."
WORD(85, 2) = "Worship the Creator not His creation."
WORD(86, 2) = "A broken friendship may be soldered, but will never be sound."
WORD(87, 2) = "A fool may ask more questions in an hour than a wise man can answer in seven years."
WORD(88, 2) = "A man of words and not of deeds is like a garden full of weeds."
WORD(89, 2) = "Believe not all that you see nor half what you hear."
WORD(90, 2) = "Early to bed and early to rise makes a man healthy, wealthy and wise."
WORD(91, 2) = "Experience keeps a dear school, but fools learn in no other."
WORD(92, 2) = "He is not fit to command others that cannot command himself."
WORD(93, 2) = "Hope is a good breakfast, but a bad supper."
WORD(94, 2) = "Money spent on the brain is never spent in vain."
WORD(95, 2) = "Poverty is not a shame, but the being ashamed of it is."
WORD(96, 2) = "We never know the value of water till the well is dry."
WORD(97, 2) = "It is a silly fish, that is caught twice with the same bait."
WORD(98, 2) = "He who would search for pearls must dive below."
WORD(99, 2) = "Creditors have better memories than debtors."
WORD(100, 2) = "Cut your coat according to your cloth."

'All the PARAGRAPH drills are stored here...
WORD(1, 3) = "The Amazon Rainforest is a moist broadleaf forest that covers most of the Amazon Basin of South America. This basin encompasses seven million square kilometers, of which five and a half million square kilometers are covered by the rainforest."
WORD(2, 3) = "Your time is limited, so don't waste it living someone else's life. Don't be trapped by dogma which is living with the results of other people's thinking. Don't let the noise of others' opinions drown out your own inner voice. And most important, have the courage to follow your heart and intuition. They somehow already know what you truly want to become. Everything else is secondary."
WORD(3, 3) = "Swami Vivekananda's inspiring personality was well known both in India and in America during the last decade of the nineteenth century and the first decade of thetwentieth. The unknown monk of India suddenly leapt into fame at the Parliament of Religions held in Chicago in 1893, at which he represented Hinduism."
WORD(4, 3) = "As of 2011, no storage system has achieved one zettabyte of information. The combined space of all computer hard drives in the world was estimated at approximately 160 exabytes in 2006. This has increased rapidly. As of 2009, the entire Internet was estimated to contain close to 500 exabytes."
WORD(5, 3) = "Infosys was founded by N. R. Narayana Murthy officially being the first employee of the company. The founders started the company with an initial investment of Rs 10,000. The company was incorporated as 'Infosys Consultants Pvt Ltd.' in Model Colony, Pune as the registered office."
WORD(6, 3) = "GSM is a cellular network, which means that mobile phones connect to it by searching for cells in the immediate vicinity. There are five different cell sizes in a GSM network - macro, micro, pico, femto and umbrella cells. The coverage area of each cell varies according to the implementation environment."
WORD(7, 3) = "Anna Hazare started an indefinite hunger strike on 5 April 2011 to exert pressure on the Indian government to enact a stringent anti-corruption law as envisaged in the Jan Lokpal Bill, for the institution of an ombudsman with the power to deal with corruption in public places."
WORD(8, 3) = "Sachin Tendulkar is an Indian cricketer widely regarded as one of the greatest batsmen in the history of cricket. He is the leading run-scorer and century maker in Test and one-day international cricket. He is the only player to score a double century in the history of ODI cricket."
WORD(9, 3) = "Facebook has affected the social life and activity of people in various ways. It can reunite lost family members and friends. One such reunion was between John Watson and the daughter he had been searching for 20 years. They met after Watson found her facebook profile. Another father-daughter reunion was between Tony Macnauton and Frances Simpson, who had not seen each other for nearly 48 years."
WORD(10, 3) = "Steve Jobs passed out in 1972 from school and joined Reed College, Oregon. But he decided to drop out from that college after one semester because it was too expensive. His economical condition was not good at that time. He later said, 'If I had never dropped in on that single course in college, the Mac would have never had multiple typefaces or proportionally spaced fonts.'"
WORD(11, 3) = "Instruments that record, analyse, summerize, debate and explain information which are illustrative, non-illustrative, hardbound paperback jackated, non-jacketed with foreward, introduction, table of contents, index that are intended for enrichment, enlightment, enhancement, understanding and education of human brain through sensory root of vision... sometimes touch."
WORD(12, 3) = "Considered a masterpieces of Marathi literature, the Dnyaneshwari's 18 chapters are composed in a metre called 'ovi'. Dnyaneshwar liberated the 'divine knowledge' locked in the Sanskrit language to bring that knowledge into Marathi and made it available to the common man. He was confident that he would write in Marathi in as good or better manner than Sanskrit."
WORD(13, 3) = "If you spend all your time and energy on the small stuff, you will never have room for the things that are important to you. Pay attention to the things that are critical to your happiness. Play with your children. Take your partner out dancing. There will always be time to go to work, clean the house, give a dinner party and fix the disposal."
WORD(14, 3) = "Father was a hardworking man who delivered bread as a living to support his wife and three children. He spent all his evenings after work attending classes, hoping to improve himself so that he could one day find a better paying job. Except for Sundays, Father hardly ate a meal together with his family. He worked and studied very hard because he wanted to provide his family with the best money could buy."
WORD(15, 3) = "At that moment, I understood the importance of saying in time: 'I LOVE YOU' and to give our loved ones the time that they deserve. Nothing in life is more important than your family. Give them the time they deserve, because these things cannot be put off till some other time.”"
WORD(15, 3) = "Oh, by the way, Mom, no one else can see what I've written except you. To everyone else this is just a blank piece of paper. Isn't that cool? I have to give God His pen back now. He needs it to write some more names in the Book of Life. Tonight I get to sit at the table with Jesus for supper. I'm, sure the food will be great."
WORD(16, 3) = "Two men, both seriously ill, occupied the same hospital room. One man was allowed to sit up in his bed for an hour each afternoon to help drain the fluid from his lungs. His bed was next to the room's only window. The other man had to spend all his time flat on his back. The men talked for hours on end."
WORD(17, 3) = "There was a blind girl who hated herself just because she was blind. She hated everyone, except her loving boyfriend. He was always there for her. She said that if she could only see the world, she would marry her boyfriend. One day, someone donated a pair of eyes to her and then she could see everything, including her boyfriend."
WORD(18, 3) = "After a long struggle, the battle was won. Dr. Kelly requested the business office to pass the final bill to him for approval. He looked at it, then wrote something on the edge and the bill was sent to her room. She feared to open it, for she was sure it would take the rest of her life to pay for it all."
WORD(19, 3) = "That night he wrote a seven-page paper describing his goal of someday owning a horse ranch. He wrote about his dream in great detail and he even drew a diagram of a 200-acre ranch, showing the location of all the buildings, the stables and the track. Then he drew a detailed floor plan for a 4,000-square-foot house that would sit on a 200-acre dream ranch."
WORD(20, 3) = "A cosmic god had a horse. The horse was beautiful and also it had many good qualities. But it wanted to be more perfect in every way. It especially wanted to become beauty unparalleled. One day the horse said to the cosmic god, 'O Lord, you have given me beauty. You have given me other good qualities. I am so grateful to you. But how I wish you could make me more beautiful.'"
WORD(21, 3) = "Real beauty lies not in the physical appearance, but in the heart. Real treasure lies not in what that can be seen, but what that cannot be seen. Real love lies not in what is done and known, but in what that is done but not known."
WORD(22, 3) = "A few miles down the road the lady saw a small cafe. She went in to grab a bite to eat, and take the chill off before she made the last leg of her trip home. It was a dingy looking restaurant. Outside were two old gas pumps. The whole scene was unfamiliar to her. The waitress came over and brought a clean towel to wipe her wet hair."
WORD(23, 3) = "The first day the boy had driven 37 nails into the fence. Over the next few weeks as he learned to control his anger, the number of nails hammered daily, gradually dwindled down. He discovered it was easier to hold his temper than to drive those nails into the fence. Finally the day came when the boy didn't lose his temper at all."
WORD(24, 3) = "She boarded the plane, and sank in her seat, then she sought her book, which was almost complete. As she reached in her baggage, she gasped with surprise, there was her bag of cookies, in front of her eyes."
WORD(25, 3) = "And to this, my mother quietly answered, 'Oh, I'm so sorry. I may have gotten the wrong address,' and she disappeared out of sight. One day, a letter regarding a school reunion came to my house. So I lied to my wife that I was going on a business trip. After the reunion, I went to the old shack just out of curiosity."
WORD(26, 3) = "Often when we face obstacles in our day-to-day life, our hurdles seem very small in comparison to what many others have to face. The Brooklyn Bridge shows us that dreams that seem impossible can be realised with determination and persistence, no matter what the odds are."
WORD(27, 3) = "It was a low building, like a small convalescent home, with a driveway that passed under a portico. Two orderlies came out to the cab as soon as we pulled up. They were solicitous and intent, watching her every move. They must have been expecting her. I opened the trunk and took the small suitcase to the door. The woman was already seated in a wheelchair."
WORD(28, 3) = "I declined to see his wounds, but did ask him what had gone through his mind as the robbery took place. 'The first thing that went through my mind was that I should have locked the back door,' Jerry replied. 'Then, as I lay on the floor, I remembered that I had two choices: I could choose to live, or I could choose to die. I chose to live.'"
WORD(29, 3) = "Thomas Edison tried two thousand different materials in search of a filament for the light bulb. When none worked satisfactorily, his assistant complained, 'All our work is in vain. We have learned nothing.' Edison replied very confidently, 'Oh, we have come a long way and we have learned a lot. We know that there are two thousand elements which we cannot use to make a good light bulb.'"
WORD(30, 3) = "There may be days when you get up in the morning and things aren't the way you had hoped they would be. That's when you have to tell yourself that things will get better. There are times when people disappoint you and let you down. But those are the times when you must remind yourself to trust your own judgments and opinions, to keep your life focused on believing in yourself."
WORD(31, 3) = "A smile costs nothing, but gives much. It enriches those who receive, without making poorer those who give. It takes a moment, but the memory of it sometimes lasts forever. None is so rich or mighty that he can get along without it, and none is so poor, but that he can be made rich by it."
WORD(32, 3) = "Abraham Lincoln never quits. Born into poverty, Lincoln was faced with defeat throughout his life. He lost eight elections, twice failed in business and suffered a nervous breakdown. He could have quit many times - but he didn't and because he didn't quit, he became one of the greatest presidents in the United States history."
WORD(33, 3) = "Imagine life as a game in which you are juggling some five balls in the air. You name them - work, family, health, friends and spirit and you're keeping all of these in the air. You will soon understand that work is a rubber ball. If you drop it, it will bounce back. But the other four balls - family, health, friends and spirit are made of glass."
WORD(34, 3) = "Let all be lost. Let them take away everything. As long as you have your heart beating strong, as long as you have your nostrils working fine, as long as the blood flows in your veins, you will live, you will breathe and you can get it all back, again and again. For, if you can do it once, you can damn well do it again. It's just a game we play - Life."
WORD(35, 3) = "Often the goal is nearer than, It seems to a faint and faltering man, Often the struggler has given up, When he might have captured the victor's cup, And he learned too late when the night slipped down, How close he was to the golden crown."
WORD(36, 3) = "Life is queer with its twists and turns, As every one of us sometimes learns, and many a failure turns about, When he might have won had he stuck it out, Don't give up though the pace seems slow- You may succeed with another blow."
WORD(37, 3) = "It is told that the man kept that gold box by his bed for years and whenever he was discouraged, he would take out an imaginary kiss and remember the love of the child who had put it there. In a very real sense, each of us as humans have been given a gold container filled with unconditional love and kisses from our children, friends, family and God. There is no more precious possession anyone could hold."
WORD(38, 3) = "Develop tendencies toward taking action. You can make something happen right now. Divide your big plan into small steps and take that first step right away. Everyone who ever got where they are had to begin where they were. Your big opportunity is where you are right now. A journey of a thousand miles begins with one step. Take it."
WORD(39, 3) = "Foolish people with all their other thoughts, have this one too: They are always getting ready to live, but never living. Your success will start when you begin to pursue it. To reach your goal or to attain success, you don't need to know all of the answers in advance. You just need to have a clear idea of what your goal is."
WORD(40, 3) = "Sometimes struggles are exactly what we need in our life. If God allowed us to go through our life without any obstacles, it would cripple us. We would not be as strong as what we could have been. And we could never fly."
WORD(41, 3) = "What are the advantages of incentive motivation? The major advantage is that it can work very well as long as the incentive is strong enough. Think of a donkey with a carrot dangling in front and with a cart behind. Incentive motivation will only work if the donkey is hungry enough, the carrot is sweet enough and the load is light enough."
WORD(41, 3) = "Motivation needs to be identified and constantly strengthened to succeed. Keep your goals in front of you and read them morning and evening. The two most important motivating factors are recognition and responsibility. Recognition means being appreciated; being treated with respect and dignity; and feeling a sense of belonging."
WORD(42, 3) = "Have you ever wondered why some individuals, organizations, or countries are more successful than others? It is not a secret. These people simply think and act more effectively. They have learned how to do so by investing in the most valuable asset--people. I believe that the success of an individual, organization or country, depends on the quality of their people."
WORD(43, 3) = "Our attitude determines how we look at a setback. To a positive thinker, it can be a stepping stone to success. To a negative thinker, it can be a stumbling block. Great organizations are not measured by wages and working conditions, they are measured by feelings, attitudes and relationships."
WORD(44, 3) = "Human nature generally resists change. Change is uncomfortable. Regardless of its positive or negative effect, change can be stressful. Sometimes we get so comfortable with our negativity that even when the change is for the positive, we don't want to accept it. We stay with the negative."
WORD(45, 3) = "Count your blessings, not your troubles. Take time to smell the roses. It is not uncommon to hear that someone, because of an accident or illness, became blind or paralyzed but won a million dollars in settlement. How many of us would like to trade places with that person? Not many. We are so focused on complaining about things we don't have that we lose sight of the things we have."
WORD(46, 3) = "Education and knowledge without common sense has little meaning. Common sense is the ability to see things as they are and do them as they ought to be done. We are born with five senses touch, taste, sight, smell, and hearing. But successful people have a sixth sense common sense. Common sense is gained in spite of, not necessarily as a result of, education."
WORD(47, 3) = "We hear every day that knowledge is power. Not really. Knowledge is information. It is potential power and it becomes power only when it is acted upon. What is the difference between a person who cannot read and a person who can but does not read? Not a whole lot.Learning is like eating food. It is not how much you eat that matters, what counts is how much you digest. Knowledge is potential power, wisdom is real power."
WORD(48, 3) = "People who do not learn lessons from history are doomed. Failure is a teacher if we have the right attitude. Failure is a detour, not a dead end. It is a delay, not a defeat. Experience is the name we give to our mistakes. Some people live and learn, and some only live. Wise people learn from their mistakes wiser people learn from other people's mistakes."
WORD(49, 3) = "When people lack purpose and direction, they see no opportunity. If a person has the desire to accomplish something, the direction to know his objective, the dedication to stay focused, and the discipline required to put in the hard work, then other things come easy. But if you don't have them, it doesn't matter what else you have."
WORD(50, 3) = "Being ignorant is not shameful, but being unwilling to learn is. Role models can teach through example. Children who are taught the importance of integrity during their formative years generally don't lose it. It becomes a part of life, which is what we are looking for in any profession, whether in a contractor, attorney, accountant, politicians police officer, or judge."
WORD(51, 3) = "Any strength overextended becomes a weakness. For example, in sales, good speaking ability is a strength. It is not uncommon to see salespeople with good speaking ability talk themselves into a sale, then talk too much and talk themselves right out of the sale. Their strength got them into it; however, ove rextended, it became a weakness and they lost the sale."
WORD(52, 3) = "Responsible behavior is to accept accountability and that represents maturity. Acceptance of responsibility is a reflection of our attitude and the environment we operate in. Most people are quick to take credit for what goes right but very few would accept responsibility when things go wrong."
WORD(53, 3) = "Cheerfulness flows from goodness. A smile can be fake or genuine. The key is to have a genuine one. It takes more muscles to frown than to smile. It is easier to smile than frown. It improves face value. A simile is contagious and is an inexpensive way to improve looks. A smiling face is always welcome."
WORD(54, 3) = "Gratitude is a beautiful word. We must be thankful. Gratitude is a feeling. It improves our personality and builds character. Gratitude develops out of humility. It is a feeling of thankfulness toward others. It is conveyed through our attitude towards others and reflects in our behavior. Gratitude does not mean reciprocating good deeds because gratitude is not give and take."
WORD(55, 3) = "Money will buy a great dog but only kindness will make him wag his tail. It is never too soon for kindness because we don't know how soon is too late. Kindness is a language the deaf can hear and the blind can see. It is better to treat a friend with kindness while he is living than display flowers on his grave when he is dead."
WORD(56, 3) = "Remember, being courteous will breed courtesy in return. Practice as much and as often as you can. Initially, it may take some effort, but the effort is well worth it. Politeness is the hallmark of gentleness. Courtesy is another name for politeness. It costs a little but pays a lot, not only to the individual but to the entire organization."
WORD(57, 3) = "Friendships are put to tests and when they endure, they grow stronger. We must learn to recognize counterfeit relationships. True friends do not want to see their friends hurt. True friendship gives more than it gets and stands by adversity."
WORD(58, 3) = "Most of our behavior is habitual. It comes automatically without thinking. Character is the sum total of our habits. If a person has positive habits, then he is considered a positive character. A person with negative habits is a negative character. Habits are a lot stronger than logic and reasoning."
WORD(59, 3) = "A person who aims at nothing never misses. Aiming low is the biggest mistake. Winners see objectives, losers see obstacles. Our goals should be high enough to motivate yet realistic enough to avoid discouragement. Anything we do, either takes us closer to our goal or further away."
WORD(60, 3) = "The uncertainty could lead to insanity. Our strongest relationships are tied together with the invisible something called commitment. Today, breaking a promise is considered no big deal. All relationships go sour without commitment."
WORD(61, 3) = "Anger is a condition in which the tongue works faster than the mind. You can't change the past, but you can ruin the present by worrying over the future. God always gives His best to those who leave the choice with Him. Laughter is God's sunshine."
WORD(62, 3) = "Everything has beauty but not everyone sees it. Thank God for what you have, TRUST GOD for what you need. If you fill your heart with regrets of yesterday and the  worries of tomorrow, you have no today to be thankful for. Happy memories never wear out.....relive them as often as you want."
WORD(63, 3) = "Take time to laugh for it is the music of the soul. Patience is the ability to idle your motor when you feel like stripping your gears. Harsh words break no bones but they do break hearts. We take for granted the things that we should  be giving thanks for. Love is the only thing that can be divided without being diminished."
WORD(64, 3) = "Happiness is enhanced by others but does not depend upon others. You are richer today if you have laughed, given or forgiven. For every minute you are angry with someone, you lose 60 seconds of happiness that you can never get back. Do what you can, for who you can, with what you have, and where you are."
WORD(65, 3) = "In front of the person you love, your heart beats faster. But in front of the person you like, you get happy. In front of the person you love, winter seems like spring. But in front of the person you like, winter is just beautiful winter. If you look into the eyes of one you love, you blush But if you look into the eyes of the person you like, you smile."
WORD(66, 3) = "In front of the person you love, you can't say everything in your mind. But in front of the person you like, you can. In front of the person you love, you tend to get shy. But in front of the person you like, you can show your own self. You can 't look straight into the eyes of the person you love. But you can always smile into the eyes of the person you like."
WORD(67, 3) = "When the one you love is crying, you cry with them. But when the one you like is crying, you end up comforting. The feeling of love starts from the eye But the feeling of like starts from the ear. So if you stop liking a person you used to like, all you need to do is cover your ears. But if you try to close your eyes, love turns into a drop of tear and remains in your heart forever..."
WORD(68, 3) = "Recently, I had this discussion around the issue of qualification for a software developer. Indian IT services companies often issue recruitment ads asking for first class engineers from the best colleges in India. Notably the IITs. That was how some of the companies started. Then they climbed down, going to the best non IIT colleges."
WORD(69, 3) = "Then they climbed down and now almost any engineer with a first class can make it through to most companies. There are many other companies who ask for best in class graduates. Some companies prefer NIIT graduates - who are not engineers, though many of them are engineers too. Really, what is the level of qualification required to be a software developer?"
WORD(70, 3) = "This is a funny question if you ask me, since it is like asking what qualification do you require to be a driver. To be a driver, you need no qualification. If you are an MA or a M Ed, well, good luck to you but that has no bearing on whether you get a driving licence or not. As long you can drive a vehicle well and convince the RTO inspector that you can, you get a licence and you can drive."
WORD(71, 3) = "To be a coder, is exactly like that. In India many people and companies make us believe that you need a science background to learn coding. It is like asking for mechanical engineers when what you really want are drivers. I have some of my friends as young as 8th standard who have waded knee deep into coding. Qualification - well nothing. Except that they loved doing what they did."
WORD(72, 3) = "Many people have no further ambition other than to learn a professional skill that supports a lifestyle that meets basic needs. For them, life is standing still. This attitude is the result of pressure, by society, to accept the status quo. Today, students are given behavior control drugs, forcing them to accept the status quo. This is the end of visionaries in our society."
WORD(73, 3) = "Journeys of unknown destinations require experiments. Every reasonable idea must be tried and tested. Testing ideas, results in gaining experience, which increases our knowledge. Very often, decisions give us an uncomfortable gut feeling long before we know the results. Gut feelings are intuitive forces that are signaling us to consider other options."
WORD(74, 3) = "Some decisions may help for a short while, and then they become wrong. A needed service or information was acquired that will be needed in the future. It is discouraging that something seems right, and then turns wrong, but this is normal. As we gain experience, quality choices become obvious."
WORD(75, 3) = "Ubuntu is a free and OpenSource operating system. Before we proceed towards Ubuntu, let's have a short idea about Linux kernel. Linux kernel was written by Linus Torwald, a Finnish software developer. Kernel is actually a heart of any operating system because it is the communication bridge between the hardware and actual data processing in the applications at runtime."
WORD(76, 3) = "The inner planets are rocky and tiny compared with such mammoths as Jupiter, Saturn, Uranus and Neptune. These planets are sometimes called at the gas giants, because they are composed largely of hydrogen and helium, which make up about 98 percent of universe. There is a huge difference in character between Mars, which is the last rocky planet and Jupiter, the first gas giant."
WORD(77, 3) = "All planets except Venus rotate from West to East. Therefore no matter where the Sun is, or where the Earch is in relation to the Sun, the East always gets the first glimpse of the Sun. Use a table lamp or a similar source of light in place of the Sun and a globe of the Earth in place of the Earth. One complete turn represents a day in the life of our planet."
WORD(78, 3) = "Astronauts face many hazards on the surface of the Moon that necessites the use of spacesuits. The spacesuits are pressurised to keep astronaut's body at the normal atmospheric pressure on Earth of 1kg per sq cm, because the Moon has no air. Without spacesuits, the astronaut's body might have exploded."
WORD(79, 3) = "When a comet nears the Sun, some of the ice vaporises, surrounding the comet with a cloud of dust and gas. Sunlight passing through this cloud, lights it up and the comet is enveloped in a fuzzy glow. Solar winds, which are caused by electrically charged particles heading in all directions, blow comets. This creates a luminous tail of all comets."
WORD(80, 3) = "Pulsars are the remnants of supernovas. They are only around 25km in diameter, and vary in their rate of spin. The fastest rotates at about 642 revolutions per second, while others turn only once per second. Because their radiation sweeps across the skies, giving out a steady pulse like beat these stars are known as pulsars."
WORD(81, 3) = "Black holes are the stars that have collapsed completely because of the tremendous force of their own gravity. Even though black holes are not visible, astronomers have found ways of locating black holes. The gravitational pull from a black hole can draw gas from a companion star. Gas spiralling into the hole gives off X-rays. Astronomers can locate the black holes by searching for these X-rays."
WORD(82, 3) = "The plate often discharges water, which turns instantly into steam. A mixture of water and silica can be explosive. The viscosity of molten rock is decided by amount of silica. If the silica content is low and that of the water is high, steam bubbles will expand in lava of low viscosity. If proportions of both water and silica are high, the thickness of discharge will trap steam bubbles until the explode."
WORD(83, 3) = "Crocodiles, which are powerful enough to kill huge prey, such as the buffalo or hippopotamus, usually leave their victims underwater until their hides soften, and then they feed in groups. Often the meal is too big and some of the meat goes rotten."
WORD(84, 3) = "Snakes cannot chew their food. They have a small teeth, which point backwards and are used to draw food into their mouth. Whatever a snake kills, it must swallow full, usually headfirst so that limbs, furs or feathers don't get grapped on their way down."
WORD(85, 3) = "Snakes have restricted senses. Their eyes detect movement at close distances, but they can't see distant objects. Their ears lack external openings, and are mainly used to control balance and to sense ground vibrations. Snakes use their tongues to lead them to prey."
WORD(86, 3) = "Spiders, which do not weave webs usually, have a stronger poison, because they have to overcome their prey more quickly, unlike web-weaving spiders, which can leave their prey to a lingering death, once they are caught in the web. Bites from spiders may cause pain or sickness in humans, but very few are fatal."
WORD(87, 3) = "The olympic flag has a link with ancient Greece. During the Ancient Olympics a sacred truce reigned. All wars in the Greek world ceased, the death penalty was suspended and safety was guaranteed to all competitors. The terms of the truce were said to inscribed in five rings on the sacred discuss of King Iphitus of Elis who first declared the armistice on the advice of the Delphic Oracle."
WORD(88, 3) = "Sumo wrestlers live in special stables and follow a strict daily regimen. When they retire from fighting, Sumo wrestlers slim rapidly. But the years of bearing the excess weight, takes its toll, as the average life of a Sumo wrestler is far below that of the average Japanese male."
WORD(89, 3) = "The first newspaper in the world is believed to have been published in China around 1300 years ago. It was called 'Tengpave'. Newspapers later began to be published in Rome and other parts of the world. A Gujrathi newspaper 'Mumbai Samachar', was the first known newspaper to be published in India."
WORD(90, 3) = "The first computer video game called 'Space War' was developed in 1962 at Massachusetts Institute of Technology by Steve Russell. Electronic games became popular in the early 1970s with a game called Pong. Due to the predictability and ease of learning, people tired of playing Pong and the fad only lasted a couple of years."
WORD(91, 3) = "The highest highways in the world are found in the northern Himalayas, partly or fully in China and Tibet. They have an extremely high average elevation, around 4-5 thousand metres above sea level. Three highways belong to this category. One between Tibet and south-western Sinkiang, another between Xining and Lhasa."
WORD(92, 3) = "Object falling freely through the atmosphere are pulled toward the Earth by gravity. Free-falling objects can attain a terminal velocity, or top speed of 118 or more miles an hour and no person can survive striking the ground with such impact."
WORD(93, 3) = "Many of the passengers and crew could not believe that the Titanic would actually sink. The evacuation was disorderly at first, but as the ship began to sink, the passengers and crew soon panicked. Most third class passengers, many of them women and children, remained trapped in the lower decks of the ship."
WORD(94, 3) = "During the course of history our ancestors have recognised and selected the best seven man-made wonders. Although the term Seven Wonders of the World is popular throughout the world, there are still some disagreements among various scholars regarding this list."
WORD(95, 3) = "The Egyptian rulers ordered the pyramids to be build so as to guard their remains from grave robbers. They chose a site on the West Side of the Nile River because they believed that the home of the dead was toward the setting sun. The burial chambers were placed under the exact centers of the pyramids."
WORD(96, 3) = "The Great Wall of China is the largest engineering and building project ever carried out by humans. It streches about 2400 kilometers from Bo Hai, a gulf off the Yellow Sea in the east. The wall is simple in structure. It is 5 to 8 meters wide, built of dirt, stone and brick. Its height ranges from 5 to 9 meters."
WORD(97, 3) = "The interior chamber of the Taj Mahal steps far beyond traditional decorative elements. Here, the inlay work is not pietra dura, but a lapidary of precious and semiprecious gemstones. The inner chamber is an octagon with the design allowing for entry from each face, although only the door facing the garden to the south is used."
WORD(98, 3) = "The Eiffel Tower is a 300 meter tower of open-lattice wrought iron. It was the tallest structure in the world at point of time. The base of the tower consists of four semicircular arches, which have the dual purpose of artistic design and weight bearing engineering considerations."
WORD(99, 3) = "The leaning tower of Pisa is 58.4 m high. It started leaning soon after the construction on the building started in 1174. In the early stages of construction, the tower leaned towards the north. Attempts were made to straighten the tower, but they resulted in the tower leaning to the south."
WORD(100, 3) = "This is the last paragraph from this course. We hope that you must have enjoyed our tutorial to improve your typing speed. We are planning to release the next version with several additional features very soon. Good bye. See you soon."

MODEINDEX = 1
STRID = 1
TB1.Text = WORD(STRID, MODEINDEX)
Call TB2_GotFocus
End Sub

Private Sub Free_Click()
Call STOPBLINK
Words.Checked = False
Sentence.Checked = False
Paragraph.Checked = False
Free.Checked = True
TB1.Font.Size = 22
TB2.Font.Size = 22
TB1.Text = ""
TB2.Text = ""
ModeName.Caption = "FreeType Mode"
TB1.Locked = False
MODEINDEX = 4
STRID = 1
TB1.Text = "Type here the text you want to practice..."
TB2.Locked = True
TB1.SelStart = 0
TB1.SelLength = Len(TB1.Text)
TB1.SelColor = &HC0C0C0
TB1.Tag = "0"
Call HIDECONTROLS
TB1.Tag = "0"
Call TB2_GotFocus
End Sub

Private Sub General_Click()
Body.Enabled = False
HelpForm.Show
End Sub

Function HIDECONTROLS() As Integer
PrevBut.Visible = False
NextBut.Visible = False
GoBut.Visible = False
SID.Visible = False
Label5.Visible = False
End Function

Function SHOWCONTROLS() As Integer
PrevBut.Visible = True
NextBut.Visible = True
GoBut.Visible = True
SID.Visible = True
Label5.Visible = True
End Function

Private Sub GoBut_Click()
If (CInt(SID.Text) >= 1 And CInt(SID.Text) <= 100) Then
STRID = CInt(SID.Text)
Call CHANGESEN
Else
MsgBox "Address is out of range.", vbCritical
End If
End Sub

Private Sub NextBut_Click()
SECOND = 0

If (STRID = 100) Then
    STRID = 1
Else
    STRID = STRID + 1
End If

Call STOPBLINK
Call CHANGESEN
Call TB2_GotFocus
Label1.Visible = False
Label2.Visible = False
Label3.Visible = False
Label4.Visible = False
End Sub

Private Sub Paragraph_Click()
SECOND = 0
Words.Checked = False
Sentence.Checked = False
Paragraph.Checked = True
Free.Checked = False
Call SHOWCONTROLS
MODEINDEX = 3
STRID = 1
ModeName.Caption = "Paragraph Mode"
TB1.Text = WORD(STRID, MODEINDEX)
TB1.Font.Size = 16
TB2.Font.Size = 16
Call CHANGESEN
TB1.SelStart = 0
TB1.SelLength = Len(TB1.Text)
TB1.SelColor = &H0&
TB1.Locked = True
TB1.Tag = 0
TB1.Locked = True
TB2.Locked = False
TB1.Tag = "1"
Call TB2_GotFocus
End Sub

Private Sub Placement_Click()
FingersPlacement.Show
Body.Enabled = False
End Sub

Private Sub PrevBut_Click()
SECOND = 0

If (STRID = 1) Then
    STRID = 100
Else
    STRID = STRID - 1
End If

Call STOPBLINK
Call CHANGESEN
Call TB2_GotFocus
Label1.Visible = False
Label2.Visible = False
Label3.Visible = False
Label4.Visible = False
End Sub

Private Sub Quit_Click()
End
End Sub

Private Sub Sentence_Click()
Words.Checked = False
Sentence.Checked = True
Paragraph.Checked = False
Free.Checked = False
Call SHOWCONTROLS
MODEINDEX = 2
ModeName.Caption = "Sentence Mode"
STRID = 1
TB1.Text = WORD(STRID, MODEINDEX)
Call CHANGESEN
TB1.SelStart = 0
TB1.SelLength = Len(TB1.Text)
TB1.SelColor = &H0&
TB1.Tag = 0
Timer2.Enabled = False
TB1.Font.Size = 22
TB2.Font.Size = 22
TB1.Locked = True
TB2.Locked = False
TB1.Tag = "1"
Call TB2_GotFocus
End Sub

Function COLOR_RESTORE()
Dim X As Integer

X = 55
While (X <= 90)
If (Box(X).BackColor = &HFF00&) Then
Box(X).BackColor = &H0&
End If
X = X + 1
Wend
SHIFTPASS = False
X = 1
While (X <= 10)
If (Finger(X).BackColor = &HFF00&) Then
Finger(X).BackColor = &HC0E0FF
End If
X = X + 1
Wend

End Function

Private Sub Speed_Click()

End Sub

Private Sub SID_Change()
If (SID.Text = " ") Then
SID.Text = ""
End If
End Sub

Private Sub SID_KeyPress(KeyAscii As Integer)
If ((KeyAscii < Asc("0") Or KeyAscii > Asc("9")) And KeyAscii <> 8) Then
KeyAscii = 0
Beep
End If

If (Len(SID.Text) >= 3 And KeyAscii <> 8) Then
KeyAscii = 0
Beep
End If
End Sub

Private Sub TB1_Click()
If (MODEINDEX = 4) Then
If (TB1.Tag = "0") Then
TB1.Tag = 1
TB1.Text = ""
TB1.SelStart = 0
TB1.SelLength = Len(TB1.Text)
TB1.SelColor = &H80000008
End If
End If
'&H00C0C0C0&
End Sub

Private Sub TB1_LostFocus()
If (MODEINDEX = 4) Then
If (TB1.Text = "") Then
TB1.Text = "Type here the text you want to practice..."
TB2.Text = ""
TB2.Locked = True
TB1.SelStart = 0
TB1.SelLength = Len(TB1.Text)
TB1.SelColor = &HC0C0C0
TB1.Tag = "0"
TB2.Locked = True
Else
TB2.Locked = False
TB1.Tag = "1"
End If
End If
End Sub

Private Sub TB2_Change()
Dim ID As Integer, CHR As String, i As Integer, J As Integer, FLAG As Boolean
On Error Resume Next

If (TB1.Text = TB2.Text) Then
    KEY = 0
    If (MODEINDEX = 3 Or MODEINDEX = 4) Then
        Call COUNTSPEED
        Label1.Visible = True
        Label2.Visible = True
        Label3.Visible = True
        Label4.Visible = True
    End If
    If (STRID <> 100) Then
        STRID = STRID + 1
    Else
        STRID = 1
    End If
    Call CHANGESEN
Else
    Timer1.Enabled = True
End If

Call COLOR_RESTORE

ID = Len(TB2.Text)
If (Left$(TB1.Text, ID) = TB2.Text) Then
TB2.SelStart = ID
TB2.SelLength = 1
TB2.SelColor = RGB(0, 0, 0)

If (ID = 1) Then
    Timer2.Enabled = True
End If

TB1.SelStart = ID - 1
TB1.SelLength = 1
TB1.SelColor = RGB(0, 0, 0)

TB1.SelStart = ID + 1
TB1.SelLength = Len(TB1.Text) - Len(TB2.Text)
TB1.SelColor = RGB(0, 0, 0)

TB1.SelStart = ID
TB1.SelLength = 1
TB1.SelColor = RGB(0, 255, 0)
CHR = TB1.SelText
KEY = Asc(CHR)

If (TB1.Text = TB2.Text) Then
KEY = 0
End If

If (KEY >= 65 And KEY <= 90) Then
SHIFTPASS = True
Else
If (KEY >= 97 And KEY <= 122) Then
KEY = KEY - 32
Else
If (KEY = 32) Then
KEY = 59
Else
If (KEY = 44) Then
KEY = 62
Else
If (KEY = 46) Then
KEY = 63
Else
If (KEY = 58 Or KEY = 59) Then
    KEY = 60
    If (KEY = Asc(58)) Then
        SHIFTPASS = True
    End If

Else
If (KEY = 34 Or KEY = 39) Then
    KEY = 61
    If (KEY = Asc(39)) Then
        SHIFTPASS = True
    End If

Else
If (KEY = 63) Then
        SHIFTPASS = True
        KEY = 64
Else
    KEY = 0
End If
End If
End If
End If
End If
End If
End If
End If

i = 1
FLAG = False

While (i <= 9)
    J = 1
    While (J <= 7)
        If (FINGERS(i, J) = KEY) Then
            FINID = i
            J = 7
            FLAG = True
        End If

        J = J + 1
    Wend
    If (FLAG = True) Then
        i = 9
    End If
    i = i + 1
Wend

Else
KEY = 55
FINID = 6
ERRCNT = ERRCNT + 1
Call COLOR_RESTORE
ID = Len(TB2.Text)
TB2.SelStart = ID - 1
TB2.SelLength = 1
TB2.SelColor = RGB(255, 0, 0)
TB2.SelStart = ID
TB2.SelLength = 1
TB2.SelColor = RGB(0, 0, 0)
End If
HERE:
End Sub

Private Sub TB2_GotFocus()
Dim i As Integer, J As Integer, FLAG As Boolean, ID As Integer, CHR As String
On Error Resume Next
Timer1.Enabled = True
If (TB1.Tag = "0") Then
Call STOPBLINK
GoTo NOBLINK
End If

ID = Len(TB2.Text)
TB2.SelStart = ID
TB2.SelLength = 1
TB2.SelColor = RGB(0, 0, 0)

If (ID = 1) Then
    Timer2.Enabled = True
End If

If (ID <> 0) Then
TB1.SelStart = ID - 1
TB1.SelLength = 1
TB1.SelColor = RGB(0, 0, 0)
End If

TB1.SelStart = ID + 1
TB1.SelLength = Len(TB1.Text) - Len(TB2.Text)
TB1.SelColor = RGB(0, 0, 0)

TB1.SelStart = ID
TB1.SelLength = 1
TB1.SelColor = RGB(0, 255, 0)
CHR = TB1.SelText
KEY = Asc(CHR)

If (TB1.Text = TB2.Text) Then
KEY = 0
End If

If (KEY >= 65 And KEY <= 90) Then
SHIFTPASS = True
Else
If (KEY >= 97 And KEY <= 122) Then
KEY = KEY - 32
Else
If (KEY = 32) Then
KEY = 59
Else
If (KEY = 44) Then
KEY = 62
Else
If (KEY = 46) Then
KEY = 63
Else
If (KEY = 58 Or KEY = 59) Then
    KEY = 60
    If (KEY = Asc(58)) Then
        SHIFTPASS = True
    End If

Else
If (KEY = 34 Or KEY = 39) Then
    KEY = 61
    If (KEY = Asc(39)) Then
        SHIFTPASS = True
    End If

Else
If (KEY = 63) Then
        SHIFTPASS = True
        KEY = 64
Else
    KEY = 0
End If
End If
End If
End If
End If
End If
End If
End If

i = 1
FLAG = False

While (i <= 9)
    J = 1
    While (J <= 7)
        If (FINGERS(i, J) = KEY) Then
            FINID = i
            J = 7
            FLAG = True
        End If

        J = J + 1
    Wend
    If (FLAG = True) Then
        i = 9
    End If
    i = i + 1
Wend

ID = Len(TB2.Text)
TB1.SelStart = ID
TB1.SelLength = 1
TB1.SelColor = RGB(0, 255, 0)
NOBLINK:
End Sub

Private Sub TB2_LostFocus()
KEY = 0
X = 55
While (X <= 90)
If (Box(X).BackColor = &HFF00&) Then
Box(X).BackColor = &H0&
End If
X = X + 1
Wend
X = 1
While (X <= 10)
If (Finger(X).BackColor = &HFF00&) Then
Finger(X).BackColor = &HC0E0FF
End If
X = X + 1
Wend
End Sub

Private Sub Timer1_Timer()
If (BLINK = True And KEY <> 0) Then
If (BLNKID = True) Then
Box(KEY).BackColor = &HFF00&
Finger(FINID).BackColor = &HFF00&
If (SHIFTPASS = True) Then

Box(58).BackColor = &HFF00&
End If
BLNKID = False
Else
Box(KEY).BackColor = &H0&
Finger(FINID).BackColor = &HC0E0FF
If (SHIFTPASS = True) Then
Box(58).BackColor = &H0&
End If
BLNKID = True
End If
End If

If (KEY = 0) Then
Call STOPBLINK
End If
End Sub

Private Sub Timer2_Timer()
SECOND = SECOND + 1
End Sub

Private Sub Words_Click()
Words.Checked = True
Sentence.Checked = False
Paragraph.Checked = False
Free.Checked = False
ModeName.Caption = "Word Mode"
MODEINDEX = 1
STRID = 1
TB1.Text = WORD(STRID, MODEINDEX)
Call SHOWCONTROLS
Call CHANGESEN
TB1.SelStart = 0
TB1.SelLength = Len(TB1.Text)
TB1.SelColor = &H0&
TB1.Tag = 0

Timer2.Enabled = False
TB1.Font.Size = 22
TB2.Font.Size = 22
TB1.Locked = True
TB2.Locked = False
TB1.Tag = "1"
Call TB2_GotFocus
End Sub
