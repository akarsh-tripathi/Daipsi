using System;
using System.Collections.Generic;
using System.Text;

namespace Daipsi.Models
{
    public class Bookmarkdata
    {
        public string Id { get; set; }
        public string UserId { get; set; }
        public string UserEmailId { get; set; }
        public string CourseVideoId { get; set; }
        public string DateBookmarked { get; set; }
        public string Downloaded { get; set; }
        public string VideoName { get; set; }
        public string VideoThumbnail { get ; set; }
        public string SubjectName { get; set; }
        public string DateUploaded { get; set; }
        public string VideoDescription { get; set; }
    }
}
