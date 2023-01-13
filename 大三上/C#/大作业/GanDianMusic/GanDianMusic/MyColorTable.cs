﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GanDianMusic
{
    public class MyColorTable : ProfessionalColorTable
    {
        public override Color MenuItemSelected
        {
            get { return Color.Red; }
        }

        public override Color MenuItemBorder
        {
            get { return Color.Red; }
        }

        public override Color MenuBorder
        {
            get { return Color.Red; }
        }
    }
}
