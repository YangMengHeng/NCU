using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GanDianMusic
{
    class DBcon
    {
        private static string constr = "server=127.0.0.1;port=3306;database=musicdb;user=root;password=YangmhSQL5549;";
        private static MySqlConnection conn = new MySqlConnection(constr);
        public static int NonQuery(string sql, MySqlParameter[] sp)
        {
            int value=-1;
            MySqlTransaction st = null;
            try
            {
                //打开数据库连接
                conn.Open();
                //开启事务
                st = conn.BeginTransaction();
                //创建对象
                MySqlCommand cmd = new MySqlCommand(sql, conn, st);
                if(sp!=null&&sp.Length!=0)
                {
                    //向命令对象cmd中添加参数
                    cmd.Parameters.AddRange(sp);
                }
                //执行对表的非查询操作
                value = cmd.ExecuteNonQuery();
                //提交事务
                st.Commit();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                //回滚事务
                if (st != null)
                {
                    st.Rollback();
                }
            }
            finally
            {
                if (conn.State == ConnectionState.Open)
                {
                    conn.Close();
                }
            }
            return value;
        }

        //执行查询操作的方法
        public static DataSet Query(string sql, MySqlParameter[] sp)
        {
            DataSet ds = null;
            try
            {
                conn.Open();
                MySqlCommand cmd = new MySqlCommand(sql, conn);
                if(sp!=null&&sp.Length!=0)
                {
                    cmd.Parameters.AddRange(sp);
                }
                MySqlDataAdapter sda = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                sda.Fill(ds);
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                if(conn.State == ConnectionState.Open)
                {
                    conn.Close();
                }
            }
            return ds;
        }


       /* public static void Main(string[] args)
        {
            string constr = "server=localhost;User Id=root;password=123456;Database=musicdb";
            MySqlConnection mycon = new MySqlConnection(constr);
            mycon.Open();
            MySqlCommand mycmd = new MySqlCommand("insert into music(Id,Name,Singer,LocalPath,Words) " +
                "values(9,'fanny','smile','C:\\study',0)", mycon);
            if (mycmd.ExecuteNonQuery() > 0)
            {
                Console.WriteLine("数据插入成功！");
            }
            Console.ReadLine();
            mycon.Close();
        }*/
    }
}
